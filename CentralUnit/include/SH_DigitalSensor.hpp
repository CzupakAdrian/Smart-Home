#pragma once

#include "SH_Device.hpp"
#include <map>
#include <memory>
#include <string>
using namespace std;

namespace SH::Devices
{
    class DigitalSensor final : public SH::Device
    {
    public:
        DigitalSensor(string name) : Device(name)
        {
        }
    };
} // namespace SH::Devices