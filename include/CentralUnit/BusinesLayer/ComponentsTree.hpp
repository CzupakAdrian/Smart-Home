#pragma once

#include "AppInterfaces.hpp"
#include "Device.hpp"

#include <set>

namespace SmartHome
{
class ComponentsTree : public ComponentsTreeAccesor
{
    std::set< Component > components;
public:
    std::set< Component > listComponents() override;
    bool tryToAddDirectory(Directory, Name) override;
};
}