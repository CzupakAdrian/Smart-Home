#pragma once

#include "BasicDefinitions.hpp"

namespace SmartHome
{
class DevicesManager
{
public:
    virtual ~DevicesManager() {};
    virtual void searchForNewDevices() = 0;
    virtual NamesList listNewDevices() = 0;
    virtual NamesList listKnownDevices() = 0;
};
}