#pragma once
#include<iostream>
#include<string>
#include"noncopyable.h"

class Timestamp
{
public:
    //无参构造 
    Timestamp();

    //有参构造
    explicit Timestamp(int64_t microSecondsSinceEpoch); //explicit禁止隐式转换

    //获取当前时间
    static Timestamp now();

    //字符串转换
    std::string toString() const;


private:
    int64_t microSecondsSinceEpoch_;
};

