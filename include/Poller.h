#pragma once

#include "noncopyable.h"
#include "Channel.h"
#include "Timestamp.h"
#include "EventLoop.h"

#include<vector>
#include<unordered_map>

//muduo库中多路事件分发器和核心IP复用模块
class Channel;
class EventLoop;

class Poller:noncopyable
{
public:
    using ChannelList = std::vector<Channel*>;

    Poller(EventLoop* Loop);
    virtual ~Poller();//虚析构函数可以支持多态性，允许在运行时通过基类指针或引用删除派生类对象，并调用正确的析构函数。

    //给所有IO复用保留统一的接口
    virtual Timestamp poll(int timeoutMs, ChannelList *activeChannels) = 0; //纯虚函数=0
    virtual void updateChannel(Channel *channel) = 0;
    virtual void removeChannel(Channel *channel) = 0;

    //判断参数channel是否在当前Poller当中
    virtual bool hasChannel(Channel *channel) const;

    //EventLoop可以通过该接口获取默认的IO复用的具体实现
    static Poller* newDefaultPoller(EventLoop* Loop);

protected:
    //map的key:sockfd value:sockfd所属的channel通道类型
   using ChannelMap = std::unordered_map<int, Channel*>;
   ChannelMap channels_;

private:
     EventLoop* ownerLoop_;//定义poller所属的事件循环EventLoop
};