#pragma once
#include <vector>
#include <string>
#include "Device.hpp"

using NamesList = std::vector<Name>; // string_view ?


namespace SmartHome
{

class DevicesGetter
{
public:
    virtual NamesList list() = 0;
    virtual Device get(Name) = 0;
    virtual ~DevicesGetter() {};
};

class DevicesAdder
{
public:
    virtual bool tryToAdd(Device) = 0;
    virtual ~DevicesAdder() {};
};

}