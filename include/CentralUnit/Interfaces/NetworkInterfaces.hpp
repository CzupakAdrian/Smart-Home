#pragma once

#include "BasicDefinitions.hpp"

#include <string>

using Message = std::string;

namespace SmartHome
{

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