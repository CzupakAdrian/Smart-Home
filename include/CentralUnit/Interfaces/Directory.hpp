#pragma once

#include "AppInterfaces.hpp"
#include "Device.hpp"
#include <set>

namespace SmartHome
{
class Directory : public ComponentsTreeAccesor
{
    Name name;
    //WeakDevicesContainer devices;
    std::set< Directory > subdirectories;
public:
    Directory(Name name) : name(name) {};

    std::set< Directory > listDirectories() override;
    std::set< Device > listDevices() override;
    bool tryToAdd(Device) override;
    bool tryToAdd(Directory) override;
    inline Name getName() const { return name; }
    //std::set< Device > listDevices();
};

inline bool operator==(const Directory & lhs, const Directory & rhs)
{
    return lhs.getName() == rhs.getName();
}

inline bool operator<(const Directory & lhs, const Directory & rhs)
{
    return lhs.getName() < rhs.getName();
}
}