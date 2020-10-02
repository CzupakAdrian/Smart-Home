#pragma once

namespace SmartHome{
    class Directory;
}

#include "Directory.hpp"
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

    virtual std::set< Directory > listDirectories() = 0;
    virtual std::set< Device > listDevices() = 0;
    virtual bool tryToAdd(Directory) = 0;
    virtual bool tryToAdd(Device) = 0;
};
}