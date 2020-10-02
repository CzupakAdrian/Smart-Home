#include "DevicesManager.hpp"

#include <algorithm>

namespace SmartHome
{

DevicesManager::DevicesManager(NetworkClientSender & sender)
    : sender(sender)
{
}

bool DevicesManager::tryToAdd(Device device)
{
    if(exists(device) and not isEmpty())
    {
        rejectedDevices.insert(device);
        return false;
    }

    devices.insert(device); 
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


void DevicesManager::searchForNewDevices()
{
    sender.send(searchReq);
}

std::set< Device > DevicesManager::listDevices()
{
    return devices;
}

std::set< Device > DevicesManager::listRejectedDevices()
{
    return rejectedDevices;
}

bool DevicesManager::tryToChangeName(Device device, Name name)
{
    return device.name != name;
}
}