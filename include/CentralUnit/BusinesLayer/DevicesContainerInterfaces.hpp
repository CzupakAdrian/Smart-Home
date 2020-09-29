#pragma once

#include "Device.hpp"
#include "BasicDefinitions.hpp"

#include <vector>
#include <string>

namespace SmartHome
{

class DevicesGetter
{
public:
    virtual NamesList list() = 0;
    virtual Device get(Name) = 0;
    virtual ~DevicesGetter() {}
};

class DevicesAdder
{
public:
    virtual bool tryToAdd(Device) = 0;
    virtual ~DevicesAdder() {}
};

}