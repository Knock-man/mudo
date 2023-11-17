#pragma once
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string>

//封装socket地址类型
class InetAddress
{
public:
    explicit InetAddress(uint16_t port,std::string ip = "127.0.0.1");
    explicit InetAddress(const sockaddr_in &addr):addr_(addr){}

    std::string toIp() const;//获取IP
    std::string toIpPort() const;//获取IP端口号
    uint16_t toPort() const;//获取端口号

    const sockaddr_in* getSockAddr() const{return &addr_;};//获取地址结构
    /*
    常量成员函数中不能修改任何非mutable的成员变量，也不能调用非常量成员函数（除非是另一个常量成员函数）。
    */
private:
    sockaddr_in addr_;
};