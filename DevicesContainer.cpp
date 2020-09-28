#include "DevicesContainer.hpp"

using namespace SmartHome;

bool DevicesContainer::tryToAdd(Device device)
{
    this->device = device;
    return true;
}

NamesList DevicesContainer::list()
{
    NamesList list;
    list.push_back(this->device.name);
    return list;
}

Device DevicesContainer::get(Name)
{
    return device;
}