#pragma once
#include <memory>
#include "Location.hpp"

namespace SH
{
    class CurrentLocation
    {
        w_Location here;
    public:
        void go_to(std::string location);
        void go_up();
    };
} // namespace SH
