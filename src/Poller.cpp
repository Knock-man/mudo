#include"Poller.h"

Poller::Poller(EventLoop* Loop):ownerLoop_(Loop){}

 //判断参数channel是否在当前Poller当中
bool Poller::hasChannel(Channel *channel) const{
    // using ChannelMap = std::unordered_map<int, Channel*>;
    ChannelMap::const_iterator it = channels_.find(channel->fd());//在poller找channel
    return it!=channels_.end() && it->second == channel;//找到了
 }