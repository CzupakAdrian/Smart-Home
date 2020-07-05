#pragma once

#include "Device.hpp"
#include <memory>
#include <string>
#include <vector>
#include <string_view>
using str_view = std::experimental::string_view;

namespace SH
{
    class Location;
    using w_Location = std::weak_ptr<Location>;
    using s_Location = std::shared_ptr<Location>;
    using v_s_Location = std::vector<s_Location>;

    class Location
    {
    private:
        w_Location superlocation;
        v_s_Location sublocations;
        v_s_Device devices;
        std::string name;

    public:
        Location(std::string name);
        ~Location();
        auto get_name()                     const -> str_view;
        auto extract_devices()              const -> std::vector<str_view>;
        auto extract_sublocations()         const -> std::vector<str_view>;
        auto get_device(str_view &name)      const -> w_Device;
        auto get_sublocation(str_view &name)
                                            const -> w_Location;
        auto get_superlocation()            const -> w_Location;
        void add_device(s_Device &&device);
        void add_device(s_Device &device);
        void add_location(s_Location &&location);
        void add_location(s_Location &location); //is it necessary?
        void add_location(std::string &name);
        void remove_location(str_view name);
        void remove_device(str_view name);
    };
} // namespace SH