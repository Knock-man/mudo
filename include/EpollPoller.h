#pragma once

#include "Poller.h"
#include "EventLoop.h"
#include "Timestamp.h"

#include<vector>
#include<sys/epoll.h>
/*
epoll的使用
    epoll_create
    epoll_ctl   add/mod/del
    epoll_wait
*/
class EpollPoller: public Poller
{
public:
    //epoll_create行为
    EpollPoller(EventLoop *Loop);
    ~EpollPoller() override;

   
   //重写基类Poller的抽象方法
    Timestamp poll(int timeoutMs, ChannelList *activeChannels) override; //epoll_wait
    void updateChannel(Channel *channel) override;// //epoll_ctl   add/mod/del 行为
    void removeChannel(Channel *channel) override; //epoll_ctl   add/mod/del 行为

private:
    static const int kInitEventListSize = 16;//events_ vector数组大小

    //填写活跃的连接
    void fillAcriveChannels(int numEvents,ChannelList *activeChannels) const;

    //更新channel通道
    void update(int operation, Channel* Channel);

    using EventList = std::vector<epoll_event>;

    int epollfd_;
    EventList events_;//vector<epoll_event> events_  ->epoll_event events_[max]
   
};
