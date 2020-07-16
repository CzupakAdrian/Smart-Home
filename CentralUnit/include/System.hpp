#pragma once

#include "Device.hpp"
#include <memory>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

namespace SH
{
    class System
    {
    private:
        string name;
        vector<shared_ptr<Device>> devices;
        // TODO add actions map as in Device;
    public:
        System();
        auto get_name() const -> string_view;

        virtual void loop() = delete;
    };
} // namespace SH
