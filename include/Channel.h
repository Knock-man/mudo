#ifndef CHANNEL_H
#define CHANNEL_H

#include"noncopyable.h"
#include"EventLoop.h"
#include"Timestamp.h" 
#include"Logger.h"

#include<memory>
#include<functional>
/*
理清楚：EvevntLoop、Channel、Poller之间的关系 =》 Reactor模型上对应 Demultiplex
*/

/*
Channel 理解为通道，封装了sockfd和其感兴趣的event，如EPOLLIN、EPOLLOUT事件
还绑定了poller返回的发生具体事件
*/
class Channel:noncopyable
{
public:
    //typedef std::function<void()> EventCallback;
    using EventCallback = std::function<void()>; //事件回调
    using ReadEventCallback = std::function<void(Timestamp)>; //只读事件回调

    Channel(EventLoop* loop, int fd);
    ~Channel();

    //fd得到poller通知以后，处理事件的
    void handleEvent(Timestamp reveiveTime);
    
    /*
    std::move 函数是一个类型转换函数，它接受一个左值引用并返回一个相应的右值引用。
    这样做的目的是告诉编译器你希望将资源的所有权从左值转移到新的对象中，以触发移动语义。
    */
    //设置回调函数对象
    void setReadCallback(ReadEventCallback cb){ readCallback_ = std::move(cb); }
    void setWriteCallback(EventCallback cb){ writeCallback_ = std::move(cb); }
    void setCloseCallback(EventCallback cb){ closeCallback_ = std::move(cb); }
    void setErrorCallback(EventCallback cb){ errorCallback_ = std::move(cb); }

    //防止当channel被手动remove掉,channel还在执行回调操作
    void tie(const std::shared_ptr<void>&);

    int fd() const { return fd_; }//返回fd
    int events() const { return events_; }//返回fd感兴趣的事件
    void set_revents( int revt){ revents_ = revt; }//设置具体发生的事件

    /*=================================================问题===============================================================*/
    //设置fd感兴趣的事件
     void enableReading(){ events_ |= kReadEvent; update(); }
     void disableReading(){ events_ &= ~kReadEvent; update(); }
     void enableWriting(){ events_ |= kWriteEvent; update(); }
     void disableWriting(){ events_ &= ~kWriteEvent; update(); }
     void disableAll(){ events_ = kNoneEvent; update(); }

    //返回fd当前的事件状态
    bool isNoneEvent() const { return events_ == kNoneEvent; }//当前fd是否注册了感兴趣的事件
    bool isWriting() const { return events_ & kWriteEvent; }//当前fd是否可写
    bool isReading() const { return events_ & kReadEvent; }//当前fd是否可读

    int index() { return index_; }
    void set_index(int idx) { index_ = idx; }

    //返回channel属于哪个Eventloop
    EventLoop* ownerLoop(){ return loop_; }

    //删除channel
    void remove();

private:
    void update();
    void handleEventWithGuard(Timestamp receiveTime);

    //fd的状态 无感兴趣事件，读感兴趣事件，写感兴趣事件
    static const int kNoneEvent;
    static const int kReadEvent;
    static const int kWriteEvent;


    EventLoop *loop_;//事件循环
    int fd_;//poller监听的对象
    int events_;//注册fd感兴趣的事件
    int revents_;//poller返回的具体发生的事件
    int index_;

    //弱指针解决循环引用问题，循环引用指的是两个或多个对象彼此保留对方的共享指针，导致无法正常释放内存，从而造成内存泄漏
    std::weak_ptr<void> tie_;
    bool tied_;

    //因为channel通道里面能够获知fd最终发生的具体的事件revents，所以它负责调用具体事件的回调操作
    ReadEventCallback readCallback_;
    EventCallback writeCallback_;
    EventCallback closeCallback_;
    EventCallback errorCallback_;
};

#endif