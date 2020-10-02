#pragma once

#include "Device.hpp"
#include <vector>

namespace SmartHome
{
class DevicesAccesor
{
public:
    virtual ~DevicesAccesor() {};

    virtual void searchForNewDevices() = 0;
    virtual std::vector<Device> listDevices() = 0;
    virtual std::vector<Device> listRejectedDevices() = 0;
};

class DevicesConfigurator
{
public:
    virtual ~DevicesConfigurator() {};

    virtual bool tryToChangeName(Device, Name) = 0;
};
}