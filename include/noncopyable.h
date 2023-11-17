#pragma once
/*
noncopyable被继承以后派生类对象可以正常构造和析构，但是不能拷贝和赋值操作
*/
class noncopyable
{
public:
    noncopyable(const noncopyable&) = delete;//删除拷贝构造
    noncopyable operator=(const noncopyable&) = delete;//删除赋值构造
protected:
    noncopyable() = default;//默认构造
    ~noncopyable() = default;//默认析构
};