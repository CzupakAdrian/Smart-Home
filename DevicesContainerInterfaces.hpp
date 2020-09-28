#pragma once
#include <vector>
#include <string_view>
#include <string>
#include "Device.hpp"

using NamesList = std::vector<std::string_view>;

namespace SmartHome
{

class DevicesGetter
{
public:
    virtual NamesList list() = 0;
    virtual Device get(std::string) = 0;
};

class DevicesAdder
{
public:
    virtual bool tryToAdd(Device) = 0;
    virtual ~DevicesAdder() {}
};

}