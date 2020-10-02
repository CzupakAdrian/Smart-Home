#pragma once

#include <string>

using Name = std::string;
using DeviceType = std::string;

namespace SmartHome
{

struct Device
{
    Name name;
    DeviceType type;

    Device(Name name, DeviceType type)
    : type(type) { this->name = name; }
};

inline bool operator==(const Device & lhs, const Device & rhs)
{
    return lhs.name == rhs.name
        && lhs.type == rhs.type;
}

inline bool operator<(const Device & lhs, const Device & rhs)
{
    return lhs.name < rhs.name
        && lhs.type < rhs.type;
}
}