#include "DevicesManager.hpp"

#include <algorithm>

namespace SmartHome
{
bool DevicesManager::tryToAdd(Device device)
{
    if( exists(device) and not isEmpty())
    {
        rejectedDevices.push_back(device);
        return false;
    }

    devices.push_back(device); 
    return true;
}

    bool DevicesManager::isEmpty()
    {
        return devices.empty();
    }

    bool DevicesManager::exists(Device & device)
    {
        return std::find(devices.begin(), devices.end(), device)
            != devices.end();
    }


void DevicesManager::searchForNewDevices() {}

std::vector< Device > DevicesManager::listDevices()
{
    return devices;
}

std::vector< Device > DevicesManager::listRejectedDevices()
{
    return rejectedDevices;
}

bool DevicesManager::tryToChangeName(Device device, Name name)
{
    return device.name != name;
}
}