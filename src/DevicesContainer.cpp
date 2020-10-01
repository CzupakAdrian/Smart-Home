#include "DevicesContainer.hpp"
#include "BasicDefinitions.hpp"
#include <algorithm>

using namespace SmartHome;

bool DevicesContainer::tryToAdd(std::unique_ptr< Device > device)
{
    if (isDuplicated(*device))
        return false;
    
    devices.push_back(std::move(device));
    return true;
}

    bool DevicesContainer::isDuplicated(Device device)
    {
        for (const auto & it : devices)
            if (it->name == device.name)
                return true;

        return false;
    }

std::vector< Device > DevicesContainer::list()
{
    std::vector< Device > list;
    for(const auto & it : devices)
    {
        list.push_back(*it);
    }
    sortByName();
    return list;
}

    void DevicesContainer::sortByName()
    {
        sort(devices.begin(), devices.end(),
            []( const std::shared_ptr< Device > & a,
                const std::shared_ptr< Device > & b) -> bool
        {
            return a->name > b->name;
        });
    }

    void DevicesContainer::sortByType()
    {
        sort(devices.begin(), devices.end(),
            []( const std::shared_ptr< Device > & a,
                const std::shared_ptr< Device > & b) -> bool
        {
            return a->type > b->type;
        });
    }

std::weak_ptr< Device > DevicesContainer::get(Device device)
{
    for (const auto & it : devices)
        if (*it == device) return it;
    throw new NoSuchItemException();
}