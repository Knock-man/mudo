#include "InetAddress.h"

#include<string.h>
#include<string.h>

//参数默认值不管在声明还是定义只能出现一次
InetAddress::InetAddress(uint16_t port, std::string ip){
    bzero(&addr_,sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
    //inet_addr 将一个点分十进制的 IP 地址字符串转换成一个无符号长整型的网络字节序的IP地址值
    //inet_ntop 将网络字节序的 IP 地址转换为可打印的字符串格式
    //string.c_str 将string对象转为字符串
}

std::string InetAddress::toIp() const{//获取IP
    char buf[64];
    inet_ntop(AF_INET,&addr_.sin_addr.s_addr,buf,sizeof(buf));
    return buf;//char 类型的数组可以隐式转换为 std::string
}

std::string InetAddress::toIpPort() const{//获取IP+端口号
    //ip:port
    char buf[64];
    inet_ntop(AF_INET,&addr_.sin_addr.s_addr,buf,sizeof(buf));
    size_t end = strlen(buf);//计算ip的有效长度
    uint16_t port = ntohs(addr_.sin_port);
    sprintf(buf+end,":%u",port); //%u 无符号十进制整数
    return buf;
    /*
    sprintf 是一个函数，它可以将一个格式化的字符串输出到一个字符数组中。

    sprintf 的函数原型如下所示：
    int sprintf(char* str, const char* format, ...);

    它接受三个参数：
    str：指向字符数组的指针，指定输出结果存储的位置。
    format：格式化字符串，指定输出的格式和内容。
    ...：可变参数列表，包含了要格式化到输出字符串中的内容。
    */
}

uint16_t InetAddress::toPort() const{//获取端口号
    return ntohs(addr_.sin_port);
}