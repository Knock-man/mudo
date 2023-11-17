#include "EpollPoller.h"
#include "Logger.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<errno.h>

const int kNew = -1;//一个channel未添加到poller中，也未注册到epoll上
const int kAdded = 1;//一个channel已经添加到poller，且注册到了epoll上
const int kDeleted = 2;//一个channel已经添加到poller中，但已经从epoll移除

EpollPoller::EpollPoller(EventLoop *Loop)
    :Poller(Loop),//调用基类构造函数初始化从基类继承的成员
    epollfd_(epoll_create(EPOLL_CLOEXEC)),//创建红黑树树根
    events_(kInitEventListSize)//初始化vector<epoll_event> events_ 大小
{
    if(epollfd_ < 0)//创建epoll出错
    {
        LOG_FATAL("epoll_create error:%d \n",errno);
    }
}

EpollPoller::~EpollPoller(){
        close(epollfd_);
}

 //重写基类Poller的抽象方法
//epoll_wait
Timestamp EpollPoller::poll(int timeoutMs, ChannelList *activeChannels)
{
    //实际上应该用LOG_DEBUG输出日志更为合理
    LOG_INFO("func=%s => fd total count:%ld\n",__FUNCTION__,channels_.size());
    //vector<epoll_event> events_
    //events_.begin()返回数组首元素的地址  *events_.begin()首元素的值  &*events_.begin()底层数组的起始地址
    //events_.size()返回的是size_t类型  使用static_cast<int> 类型转换运算符
    int numEvents = epoll_wait(epollfd_,&*events_.begin(),static_cast<int>(events_.size()),timeoutMs);

    int saveErrno = errno;
    //问题
    Timestamp now(Timestamp::now());//记录发生事件的时间

    if(numEvents > 0)
    {
        LOG_INFO("%d events happened \n",numEvents);
        fillAcriveChannels(numEvents,activeChannels);
        if(numEvents == events_.size())//发生事件的个数等于events_ 中的事件个数  vector<epoll_event> events_
        {
            events_.resize(events_.size() * 2); //进行扩容
        }
    }
    else if(numEvents == 0)
    {
        LOG_DEBUG("%s timeout! \n",__FUNCTION__);
    }
    else
    {
        if(saveErrno != EINTR)
        {
            errno = saveErrno;//防止errno中途被更改(39行之后)
            LOG_ERROR("EPollPoller::poll() err!");
        }
    }
    return now;

}

//填写活跃连接
void EpollPoller::fillAcriveChannels(int numEvents,ChannelList *activeChannels) const
{
    for(int i=0; i<numEvents; i++)
    {
        Channel *channel = static_cast<Channel*>(events_[i].data.ptr);
        channel->set_revents(events_[i].events);
        activeChannels->push_back(channel);//EventLoop就拿到了它的poller给它返回的所有发生事件的channel列表了
    }
}

//epoll_ctl   add/mod/del 行为
//channel update remove => EventLoop updateChanel removeChannel => Poller updateChanel removeChannel
/*
            EventLoop
    ChannelList         Poller
                ChannelMap<fd,channel>

*/
void EpollPoller::updateChannel(Channel *channel)
{
    const int index = channel->index();//index表示channel的状态 -》 kNew kAddef kDeleted
    LOG_INFO("func=%s => fd=%d events=%d index=%d \n",__FUNCTION__,channel->fd(), channel->events(), index);
    
    if(index == kNew || index == kDeleted)//channel还未在poller和epoll上注册过，或者poller注册过，在epoll中删除了
    {
        if(index == kNew)//从未添加到poller中
        {
            int fd = channel->fd();
            channels_[fd] = channel;//添加到poller中
        }
        channel->set_index(kAdded);//设置channel状态为已添加
        update(EPOLL_CTL_ADD,channel);//挂入epoll中
    }
    else//channel已经在poller上和epoll注册过了
    {
        int fd = channel->fd();
        if(channel->isNoneEvent())//对任何事件不感兴趣
        {
            update(EPOLL_CTL_DEL,channel);//从epoll中删除
            channel->set_index(kDeleted);
        }
        else//有感兴趣的事件
        {
            update(EPOLL_CTL_MOD,channel);
        }

    }
}

//epoll_ctl   add/mod/del 行为
//从 poller中删除channel
void EpollPoller::removeChannel(Channel *channel)
{
    int fd = channel->fd();
    channels_.erase(fd);//从poller中移除

    LOG_INFO("func=%s => fd=%d\n",__FUNCTION__,channel->fd());


    int index = channel->index();
    if(index == kAdded)//已经注册到poller和epoll中
    {
        update(EPOLL_CTL_DEL,channel);//从epoll中移除
    }
    channel->set_index(kNew);//状态设为从未在poller和epoll中注册过

}

//更新channel通道
void EpollPoller::update(int operation, Channel* Channel)
{
    struct epoll_event event;
    memset(&event,0,sizeof(event));
    event.events = Channel->events();
    event.data.ptr = Channel;
    int fd = Channel -> fd();
    event.data.fd = fd;

    if(epoll_ctl(epollfd_,operation,fd,&event) < 0)//对epoll进行操作
    {
        if(operation == EPOLL_CTL_DEL)
        {
            LOG_ERROR("epoll_ctl del error:%d\n",errno);
        }
        else
        {
            LOG_FATAL("epoll_ctl add/mod error:%d\n",errno);
        }
        
    }

}



