#pragma once 

#include<unistd.h>
#include<sys/syscall.h>

namespace CurrentThread
{
    /*
        __thread: 这是一个线程局部存储的修饰符。它指示编译器为每个线程创建一个独立的t_cachedTid变量的副本。
                    这样，每个线程都拥有它自己的t_cachedTid变量，互不干扰。

        对于变量的声明：使用 extern 关键字可以在一个源文件中声明一个全局变量，而实际的定义可以在其他的源文件中。
            这样做可以将变量的定义和声明分离开来，方便程序的组织和管理。例如，可以在一个源文件中声明一个全局变量 extern int globalVariable;
            而该变量的实际定义可以在另一个源文件中进行，比如 int globalVariable = 10;。这样，在需要使用该全局变量的源文件中，只需要包含该变量的声明即可。
        对于函数的声明：使用 extern 关键字可以声明一个外部函数，表明该函数的定义在其他地方
            例如，可以在一个源文件中声明一个外部函数 extern void externalFunction();，而函数的实际定义可以在另一个源文件中。
            这样，在需要调用该函数的源文件中，只需包含该函数的声明即可。
    
        普通函数调用涉及保存和恢复现场、传递参数、跳转等操作，而内联函数通过直接将函数的代码插入调用点，减少了这些开销。内联函数适用于函数体较短的情况，内联函数是一种编译器优化技术
    
        namespace:在编程中，命名空间（namespace）是用来组织代码和标识符（变量、函数、类等）的一种方式。
                它可以避免不同部分的代码之间的命名冲突，并提供了一种更清晰和有层次结构的代码组织方式。
    
    */
   extern __thread int t_cachedTid;

   void cacheTid();//包括获取当前线程的线程 ID

    inline int tid()
   {
        if(__builtin_expect(t_cachedTid == 0, 0))//t_cachedTid==0  还没获取当前线程的tid  
        {
            cacheTid();
        }
        return t_cachedTid;//t_cachedTid != 0已经获取，直接返回
   }


}