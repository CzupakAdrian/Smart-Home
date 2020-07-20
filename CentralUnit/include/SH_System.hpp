#pragma once

#include "SH_Location.hpp"
#include "SH_Device.hpp"
#include <memory>
#include <string>
#include <string_view>
#include <vector>

//TODO remove using namespace std from .hpps

namespace SH
{
    class System
    {
    private:
        std::string name;
        std::vector<std::shared_ptr<Device>> devices;
        std::weak_ptr<Location> superlocation;
        // TODO add actions map as in Device;
    public:
        System();
        auto get_name() const -> std::string_view;

        void set_superlocation(std::weak_ptr<Location>);
        //virtual void loop() = delete;
    };
} // namespace SH
