#pragma once

#include "Device.hpp"
#include <set>

namespace SmartHome
{
class DevicesAccesor
{
public:
    virtual ~DevicesAccesor() {};

    virtual void searchForNewDevices() = 0;
    virtual std::set< Device > listDevices() = 0;
    virtual std::set< Device > listRejectedDevices() = 0;

    virtual bool tryToChangeName(Device, Name) = 0;

};


class ComponentsTreeAccesor
{
public:
    virtual ~ComponentsTreeAccesor() {};

    virtual std::set< Component > listComponents() = 0;
    virtual bool tryToAddDirectory(Directory, Name) = 0;
};
}