#pragma once

#include "Handler.hpp"
#include <memory>
#include <string>
#include <vector>
#include <string_view>
using str_view = std::experimental::string_view;

namespace SH
{
    class Device;
    using w_Device = std::weak_ptr<Device>;
    using s_Device = std::shared_ptr<Device>;
    using v_s_Device = std::vector<s_Device>;
    
    class Device
    {
    protected:
        std::string name;
        std::string type;
        std::vector<std::unique_ptr<Handler>> handlers;

    public:
        auto get_name() const -> str_view;
    };
} // namespace SH