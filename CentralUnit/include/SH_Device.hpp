// Base class for all devices in Smart-Home system -*- C++ -*-

// Copyright (C) 2020 czupakadrian@gmail.com

#pragma once

#include "SH_Location.hpp"
#include "SH_NetworkInterface.hpp"
#include "SH_Action.hpp"
#include <map>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

namespace SH
{
    class Device: private enable_shared_from_this<Device>
    {
    private:
        NetworkInterface network;
        string name;
        string type;
        map<string, unique_ptr<Action>> actions;

    protected:
        Device(string &name, string &type, NetworkInterface net_interface);

    public:
        Device() = delete;
        Device &operator=(Device&) = delete;
        ~Device();
        auto get_name() const -> string_view;
        auto get_type() const -> string_view;
        auto act(const string &action_name, const string &params) -> action_output;
        void set_network_interface(NetworkInterface &&);
        void set_superlocation(weak_ptr<Location>);
    };
} // namespace SH