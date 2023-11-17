#include "EventLoop.h"
#include "Logger.h"
#include <fcntl.h>
#include <fcntl.h>
#include <sys/eventfd.h>

//防止一个线程创建多个EvenntLoop 
__thread EventLoop *t_loopInThisThread = nullptr;

//定义默认的poller IO复用接口的超时时间
const int kPollTimeMs = 10000;

//创建wakeupfd，用来notify唤醒subReactor处理新的channel
int createEventfd()
{
    int evtfd = eventfd(0,EFD_NONBLOCK | EFD_CLOEXEC);
    if(evtfd < 0)
    {
        LOG_FATAL("eventfd error:%d \n",errno);
    }
    return evtfd;
}

EventLoop::EventLoop():
        looping_(false),
        quit_(false),
        callingPendingFunctors_(false),
        threadId_(CurrentThread::tid()),
        poller_(Poller::newDefaultPoller(this)),
        wakeupFd_(createEventfd()),
        wakeupChannel_(new Channel(this,wakeupFd_)),
        currentActiveChannel_(nullptr)
{
    LOG_DEBUG("EventLoop create %p in thread %d \n",this,threadId_);
    if(t_loopInThisThread)
    {
        LOG_FATAL("Another EventLoop %p exists in this thread %d \n",t_loopInThisThread, threadId_);
    }
    else
    {
        t_loopInThisThread = this;
    }
}
EventLoop::~EventLoop(){

}