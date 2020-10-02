#pragma once

#include <string>

namespace SmartHome
{
using Message = std::string;

class NetworkClientSender
{
public:
    virtual ~NetworkClientSender() {};
    
    virtual void send(Message) = 0;
};

class NetworkClientReceiver
{
public:
    virtual void receive(Message) = 0;
};

}