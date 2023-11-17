#include"Timestamp.h"

#include<time.h>

    //无参构造 
    Timestamp::Timestamp():microSecondsSinceEpoch_(0){};

    //有参构造
    Timestamp::Timestamp(int64_t microSecondsSinceEpoch):microSecondsSinceEpoch_(microSecondsSinceEpoch){};

    //获取当前时间
    Timestamp Timestamp::now(){
        return Timestamp(time(NULL));//time返回时间秒数
        /*
        time(NULL):返回自协调世界时 (UTC) 的1970年1月1日00:00:00 到当前时间的秒数
        Timestamp(time(NULL)):调用Timestamp析构函数，创建对象返回
        */
    }

    //时间格式字符串转换
    std::string Timestamp::toString() const
    {
        char buf[128] = {0};
        tm *tm_time = localtime(&microSecondsSinceEpoch_);
        snprintf(buf,128,"%4d/%02d/%02d %02d:%02d:%02d",
        tm_time->tm_year + 1900,
        tm_time->tm_mon + 1,
        tm_time->tm_mday,
        tm_time->tm_hour,
        tm_time->tm_min,
        tm_time->tm_sec);
        return std::string(buf);
    }