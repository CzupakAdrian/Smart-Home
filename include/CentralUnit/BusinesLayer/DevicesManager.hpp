#pragma once

#include "AppInterfaces.hpp"
#include "NetworkInterfaces.hpp"
#include "Device.hpp"

#include <memory>
#include <set>


namespace SmartHome
{
const Message searchReq = "aa";

class DevicesAdder
{
public:
    virtual ~DevicesAdder() {};

    virtual bool tryToAdd(Device) = 0;
};

class DevicesManager
    : public DevicesAccesor
    , public DevicesAdder
{
    NetworkClientSender & sender;
    std::set< Device > devices;
    std::set< Device > rejectedDevices;

public:
    DevicesManager(NetworkClientSender &);

    void searchForNewDevices() override;
    std::set< Device > listDevices() override;
    std::set< Device > listRejectedDevices() override;
    bool tryToChangeName(Device, Name) override;
    bool tryToAdd(Device) override;

private:
    bool isEmpty();
    bool exists(Device &);
};
}