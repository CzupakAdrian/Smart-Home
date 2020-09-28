#pragma once

#include "DevicesContainerInterfaces.hpp"
#include "Device.hpp"

namespace SmartHome
{
class DevicesContainer
    : public DevicesAdder
    , public DevicesGetter
{
    Device device;

public:
    bool tryToAdd(Device) override;
    NamesList list() override;
    Device get(Name) override;
};

inline bool operator==(const Device & lhs, const Device & rhs) { return lhs.name == rhs.name; }
}