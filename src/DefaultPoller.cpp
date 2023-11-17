/*
newDefaultPoller()函数属于Poller类中的静态函数 为什么要单独创建这个文件?而不是直接在Poller.cpp中实现
答：如果newDefaultPoller()函数直接在Poller.cpp文件中实现，需要在newDefaultPoller生成poll或epoll的实例，
    需要引用 #include"poll.h" #include"epoll.h" 头文件，但是Poller为基类，poll/epoll为派生类
    基类文件 引用(依赖) 派生类文件 违反编程规范，故单独创一个公共文件编写

*/
#include "Poller.h"
#include "EpollPoller.h"
#include<stdlib.h>

Poller* Poller::newDefaultPoller(EventLoop* Loop){
    if(getenv("MUDUO_USE_POLL"))//判断环境变量是否存在MUDUO_USE_POLL
    {
        return nullptr;//生成poll的实例
    }
    else
    {
        return new EpollPoller(Loop);//生成epoll的实例 
    }
}
