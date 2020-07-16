#include "Location.hpp"
using namespace std;

using SH::Location;
using SH::Device;
using SH::System;
using SH::getters_params_type;

// **************************************************************************
//              Static members
// **************************************************************************
template <typename cont_type>
auto Location::get_iterator_by_name(getters_params_type name, cont_type &containter) -> cont_type::iterator
{
    return find_if(
        containter.begin(),
        containter.end(),
        [name](const shared_ptr<cont_type> &it){ return it->get_name() == name; }
    );
}

// **************************************************************************
//              Basic operations
// **************************************************************************
Location::Location(string &name)
: name(name)
{}

// **************************************************************************
Location::~Location()
{
    // TODO it should ask if user wants to remove existing systems
    // or to transport them to superlocation
}

// **************************************************************************
auto Location::get_name() const -> string_view
{
    // TODO lets check it's possible to just 'return name;'
    string_view output = name;
    return move(output);
}

void Location::change_name(const string &new_name)
{
    name = new_name;
}

// **************************************************************************
//              Extractors
// **************************************************************************
auto Location::extract_devices() const
-> vector<string_view>
{
    vector<string_view> names;
    for(const auto& it : devices)
    {
        names.push_back(it->get_name());
    }
    return move(names);
}

// **************************************************************************
auto Location::extract_sublocations() const
-> vector<string_view>
{
    vector<string_view> names;
    for (const auto& it : sublocations)
    {
        names.push_back(it->get_name());
    }
    return move(names);       
}

// **************************************************************************
auto Location::extract_systems() const
-> vector<string_view>
{
    vector<string_view> names;
    for (const auto &it : systems)
    {
        names.push_back(it->get_name());
    }
    return move(names);
}

// **************************************************************************
//              Getters
// **************************************************************************
auto Location::get_device(getters_params_type name)
-> weak_ptr<Device>
{
    return *get_iterator_by_name<decltype(devices)>(name, devices);
}

// **************************************************************************
auto Location::get_sublocation(getters_params_type name)
-> weak_ptr<Location>
{
    return *get_iterator_by_name<decltype(sublocations)>(name, sublocations);
}

// **************************************************************************
auto Location::get_superlocation() const
-> weak_ptr<Location>
{
    return superlocation;
}

// **************************************************************************
auto Location::get_system(getters_params_type name)
-> weak_ptr<System>
{
    return *get_iterator_by_name<decltype(systems)>(name, systems);
}

// **************************************************************************
//              Adders
// **************************************************************************
void SH::Location::add_device(shared_ptr<Device> &&new_device)
{
    devices.push_back(std::move(new_device));
}

// **************************************************************************
void Location::add_location(shared_ptr<Location> &&new_location)
{
    sublocations.push_back(move(new_location));
}

// **************************************************************************
void Location::add_location(const string &name)
{
    sublocations.push_back(make_shared<Location>(name));
}

// **************************************************************************
void Location::add_system(shared_ptr<System> &&new_system)
{
    systems.push_back(move(new_system));
}

// **************************************************************************
//              Removers
// **************************************************************************
// TODO secure removers from removing when for example device is being used by some system
void Location::remove_device(getters_params_type name)
{
    devices.erase(get_iterator_by_name<decltype(devices)>(name, devices));
}

// **************************************************************************
void Location::remove_location(getters_params_type name)
{
    sublocations.erase(get_iterator_by_name<decltype(sublocations)>(name, sublocations));
}

// **************************************************************************
void Location::remove_system(getters_params_type name)
{
    systems.erase(get_iterator_by_name<decltype(systems)>(name, systems));
}