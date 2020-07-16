// Base class for all devices in Smart-Home system -*- C++ -*-

// Copyright (C) 2020 czupakadrian@gmail.com

#pragma once

#include "NetworkInterface.hpp"
#include "Action.hpp"
#include <map>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

namespace SH
{
    class Device
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
    };
} // namespace SH