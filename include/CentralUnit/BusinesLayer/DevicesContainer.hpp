#pragma once

#include "BasicDefinitions.hpp"
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
    ~DevicesContainer() {}
    bool tryToAdd(Device) override;
    NamesList list() override;
    Device get(Name) override;

private:
    bool isDuplicated(Device);
};

inline bool operator==(const Device & lhs, const Device & rhs) { return lhs.name == rhs.name; }
}