#pragma once
#include <string>

using Message = std::string;

namespace SmartHome
{

class NetworkClientSender
{
public:
    virtual void send(Message) = delete;
};

class NetworkClientReceiver
{
public:
    virtual void receive(Message) = delete;
};

}