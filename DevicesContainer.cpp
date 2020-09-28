#include "DevicesContainer.hpp"
#include <exception>
#include <algorithm>

using namespace SmartHome;

bool DevicesContainer::tryToAdd(Device device)
{
    for (const auto & it : devices)
        if (it.name == device.name) return false;
    devices.push_back(device);
    return true;
}

NamesList DevicesContainer::list()
{
    NamesList list;
    for(const auto & it : devices)
        list.push_back(it.name);
    std::sort(list.begin(), list.end());
    return list;
}

struct NoSuchItemException : public std::exception
{
    const char * what() const throw() { return "No such item"; }
};

Device DevicesContainer::get(Name name)
{
    for (const auto & it : devices)
        if (it.name == name) return it;
    throw new NoSuchItemException();
}