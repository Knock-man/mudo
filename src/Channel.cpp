#include"Channel.h"
#include"EventLoop.h"

#include<sys/epoll.h>


//fd的状态 无感兴趣事件，读感兴趣事件，写感兴趣事件
const int kNoneEvent = 0;
const int kReadEvent = EPOLLIN | EPOLLPRI;
const int kWriteEvent = EPOLLOUT;

Channel::Channel(EventLoop *loop, int fd):
        loop_(loop), 
        fd_(fd), 
        events_(0), 
        revents_(0),
        index_(-1),
        tied_(false){

}
Channel::~Channel(){}

//channel的tie方法在什么时候调用过
void Channel::tie(const std::shared_ptr<void> &obj)//tie_弱指针绑定obj强指针
{
    tie_ = obj;
    tied_ = true;
}

//当改变chanel所表示fd的events事件后，update负责在poller里面更改相应事件epoll_ctl
 void Channel::update()
 {
    //通过chanel所属的EventLoop，调用poller的相应方法，注册fd的events事件
    //add code ...
    //loop->updateChannel(this);
 }

 //在channel所属的EventLoop中，把当前的channel删除掉
void Channel::remove()
{
    //add code ...
    //loop_->removeChannel(this);
}

//fd得到poller通知以后，处理事件的
void Channel::handleEvent(Timestamp receiveTime)
{
    if(tied_)
    {
        std::shared_ptr<void> guard = tie_.lock();
        if(guard)
        {
            handleEventWithGuard(receiveTime);
        }
    }
    else
    {
        handleEventWithGuard(receiveTime);
    }
}

//根据poller通知的channel发生的具体事件，由channel负责调用具体的回调操作
void Channel::handleEventWithGuard(Timestamp receiveTime)
{
    //打印普通日志
    LOG_INFO("channel handleEvent revents:%d\n",revents_);
    
    //文件描述符挂断连接 并且 没有可读数据
    if((revents_ & EPOLLHUP) && !(revents_ & EPOLLIN))
    {
        if(closeCallback_)
        {
            closeCallback_();
        }
    }
    //文件描述符发生错误
    if(revents_ & EPOLLERR)
    {
        if(errorCallback_)
        {
            errorCallback_();
        }
    }
    //有可读事件
    if(revents_ & (EPOLLIN | EPOLLPRI))
    {
        if(readCallback_)
        {
            readCallback_(receiveTime);
        }
    }
    //有可写事件
    if(revents_ & EPOLLOUT)
    {
        if(writeCallback_)
        {
            writeCallback_();
        }
    }
}