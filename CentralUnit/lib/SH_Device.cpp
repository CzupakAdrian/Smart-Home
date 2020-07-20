#include "SH_Device.hpp"
using namespace std;
using SH::Device;
using SH::NetworkInterface;

// **************************************************************************
//              Constructors and Destructor
// **************************************************************************

Device::Device(string &name, string &type, NetworkInterface net_interface)
: name(name)
, type(type)
{
    // TODO make sure how to pass NetworkInterface and how to initialize it
}

Device::~Device()
{
    // TODO secure destructor from data loss
}

// **************************************************************************
//              Getters
// **************************************************************************

auto Device::get_name() const -> string_view
{
    // FIXME if 'return name;' doesn't work, then do it as in 'Location'
    return name;
}

// **************************************************************************
auto Device::get_type() const -> string_view
{
    // FIXME as in 'get_name()'
    return type;
}

// **************************************************************************
//              Action methods
// **************************************************************************

auto Device::act(const string &action_name, const string &params)
-> action_output
{
    return actions[action_name]->act(params);
}

// **************************************************************************

void Device::set_network_interface(NetworkInterface &&new_network)
{
    network = new_network;
}
