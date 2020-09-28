#pragma once

#include "DevicesContainerInterfaces.hpp"
#include "Device.hpp"

namespace SmartHome
{
class DevicesContainer : public DevicesAdder
{
public:
    bool tryToAdd(Device) override;
};
}