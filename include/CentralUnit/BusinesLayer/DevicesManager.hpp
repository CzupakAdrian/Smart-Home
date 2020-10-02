#pragma once

#include "AppInterfaces.hpp"
#include "NetworkInterfaces.hpp"
#include "Device.hpp"

#include <memory>
#include <vector>


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
    , public DevicesConfigurator
    , public DevicesAdder
{
    std::vector< Device > devices;
    std::vector< Device > rejectedDevices;

public:
    DevicesManager(NetworkClientSender & sender);

    void searchForNewDevices() override;
    std::vector< Device > listDevices() override;
    std::vector< Device > listRejectedDevices() override;
    bool tryToChangeName(Device, Name) override;
    bool tryToAdd(Device) override;

private:
    bool isEmpty();
    bool exists(Device &);
};
}