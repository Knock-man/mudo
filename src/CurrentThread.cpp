#include "CurrentThread.h"
/*
syscall(SYS_gettid)是一个Linux系统下的系统调用，用于获取当前线程的线程ID（tid）。它会返回一个整数值，表示当前线程的唯一标识符。
可以通过pthread_self()函数来获取该线程的ID，也可以通过syscall(SYS_gettid)系统调用来获取。
相比于pthread_self()函数，syscall(SYS_gettid)是一种更底层、更直接的方式来获取当前线程的线程ID。
*/
namespace CurrentThread
{

    __thread int t_cachedTid = 0;

//包括获取当前线程的线程 ID
   void cacheTid()
   {
        if(t_cachedTid == 0)
        {
            //通过linux系统调用获取当前线程的tid值
            t_cachedTid = static_cast<pid_t>(syscall(SYS_gettid));
        }
   }



   
}