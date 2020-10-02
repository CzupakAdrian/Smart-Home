#pragma once

#include <string>

using Name = std::string;
using DeviceType = std::string;

namespace SmartHome
{
struct Component
{
    Name name;

    virtual ~Component() {};
};

class Directory : public Component
{
public:
    Directory(Name name)
    { this->name = name; }
};

struct Device : public Component
{
    DeviceType type;

    Device(Name name, DeviceType type)
    : type(type) { this->name = name; }
};

inline bool operator==(const Component & lhs, const Component & rhs)
{
    return lhs.name == rhs.name;
}

inline bool operator<(const Component & lhs, const Component & rhs)
{
    return lhs.name < rhs.name;
}

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