#pragma once

#include "DevicesContainerInterfaces.hpp"
#include "Device.hpp"

#include <vector>

namespace SmartHome
{
class DevicesContainer
    : public DevicesAdder
    , public DevicesGetter
{
    std::vector<Device> devices;

public:
    bool tryToAdd(Device) override;
    NamesList list() override;
    Device get(Name) override;
};

inline bool operator==(const Device & lhs, const Device & rhs) { return lhs.name == rhs.name; }
}