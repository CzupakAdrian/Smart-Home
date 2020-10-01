#pragma once

#include "Device.hpp"

#include <vector>
#include <memory>

namespace SmartHome
{
class DevicesContainer
{
    std::vector< std::shared_ptr< Device >> devices;

public:
    ~DevicesContainer() {}
    bool tryToAdd(std::unique_ptr< Device >) ;
    std::vector<Device> list();
    std::weak_ptr<Device> get(Device);

private:
    bool isDuplicated(Device);
    void sortByName();
    void sortByType();
};
}