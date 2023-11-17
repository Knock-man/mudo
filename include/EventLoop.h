#pragma once

#include<functional>
#include<vector>
#include<atomic>
#include<memory>
#include<mutex>

#include "CurrentThread.h"
#include "Channel.h"
#include "noncopyable.h"
#include "Poller.h"
#include "Timestamp.h"

class  Poller;
class  Channel;

//时间循环类 主要包含了两个大模块 Channel Poller(epoll的抽象)
class EventLoop
{
public:
    using Functor = std::function<void()>;
    EventLoop();
    ~EventLoop();

    //开启事件循环
    void loop();
    //退出事件循环
    void quit();   

    Timestamp pollReturnTime() const{ return pollReturnTime_; }

    //在当前loop中执行cb
    void runInloop(Functor cb);
    //把cb放入队列中，唤醒loop所在的线程，执行cb
    void queueInLoop(Functor cb);
    //唤醒loop所在的线程的
    void wakeup();
    //EventLoop的方法 => Poller的方法
    void updateChannel(Channel *Channel);
    void removeChannel(Channel *channel);
    bool hasChannel(Channel *Channel);
    //判断EventLoop对象是否在自己的线程里面
    bool isInLoopTread() const{ return threadId_ == CurrentThread::tid();};

private:
    void handleRead();//唤醒
    void doPendingFunctors();//执行回调

    using ChannelList = std::vector<Channel*>;

    /*
    原子操作通常用于多线程编程中，其中并发访问共享数据结构可能会导致数据不一致的问题。
    通过使用原子操作，可以确保每个线程能够对共享资源进行原子性操作，从而避免出现数据访问冲突的情况。

            std::atomic<bool>：原子布尔类型，用于原子性操作布尔值。
            std::atomic<int>：原子整型，用于原子性操作整数值。
            std::atomic<long>：原子长整型，用于原子性操作长整数值。
            std::atomic<double>：原子双精度浮点型，用于原子性操作双精度浮点数值。
            std::atomic<T*>：原子指针类型，用于原子性操作指针。
            std::atomic<std::shared_ptr<T>>：原子共享指针类型，用于原子性操作共享指针。
        这些原子类型都提供了一系列的操作函数，用于读取、写入和进行原子性的比较和交换操作。一些常用的操作函数包括：
            load()：原子地读取当前值。
            store()：原子地写入新值。
            exchange()：原子地交换当前值并返回旧值。
            compare_exchange_strong()：如果当前值与期望值相等，则用新值替换当前值，返回替换前的值。
            fetch_add()：原子地将当前值与给定的增量相加，并返回原值。
            fetch_sub()：原子地将当前值与给定的减量相减，并返回原值。
    */

    std::atomic<bool> looping_; //原子操作,通过CAS实现的

    std::atomic<bool> quit_; //标识退出loop循环

    const pid_t threadId_;//记录当前loop所在线程的id

    Timestamp pollReturnTime_;//poller返回发生事件的channels的时间点
    std::unique_ptr<Poller> poller_;

    int wakeupFd_;//主要作用,当mainLoop获取一个新用户的chanel,通过轮询算法选择一个subloop,通过该成员唤醒subloop处理chanel
    std::unique_ptr<Channel> wakeupChannel_;

    ChannelList avtiveChannels_;
    Channel *currentActiveChannel_;

   std::atomic<bool> callingPendingFunctors_;//标识当前loop是否有需要执行的回调操作
   std::vector<Functor> pendingFunctors_;//存储loop需要执行的所有回调操作
   std::mutex mutex_;//互斥锁用来保护上面vector容器的线程安全操作
};
