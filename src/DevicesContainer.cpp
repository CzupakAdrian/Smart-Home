#include "DevicesContainer.hpp"
#include <algorithm>

using namespace SmartHome;

bool DevicesContainer::tryToAdd(Device device)
{
    if (isDuplicated(device))
        return false;
    
    devices.push_back(device);
    return true;
}

bool DevicesContainer::isDuplicated(Device device)
{
    for (const auto & it : devices)
        if (it.name == device.name)
            return true;

    return false;
}

NamesList DevicesContainer::list()
{
    NamesList list;
    for(const auto & it : devices)
        list.push_back(it.name);
    std::sort(list.begin(), list.end());
    return list;
}

Device DevicesContainer::get(Name name)
{
    for (const auto & it : devices)
        if (it.name == name) return it;
    throw new NoSuchItemException();
}