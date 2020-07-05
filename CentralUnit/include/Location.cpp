#include "Location.hpp"

SH::Location::Location(std::string name)
: name(name)
{}

SH::Location::~Location()
{
    //      it should ask if user wants to remove existing systems
    // or to transport them to superlocation
}

auto SH::Location::extract_devices() const
-> std::vector<str_view>
{
    std::vector<str_view> names;
    for(const auto& it : devices)
    {
        names.push_back(it->get_name());
    }
    return names;
}

auto SH::Location::extract_sublocations() const
-> std::vector<str_view>
{
    std::vector<str_view> names;
    for (const auto& it : sublocations)
    {
        names.push_back(it->get_name());
    }
    return names;       
}

auto SH::Location::get_device(str_view &name) const
-> SH::w_Device
{
    for (const auto& it : devices)
    {
        if (it->get_name() == name)
        {
            return it;
        }
    }
}

auto SH::Location::get_sublocation(str_view &name) const
-> SH::w_Location
{
    for (const auto& it : sublocations)
    {
        if (it->get_name() == name)
        {
            return it;
        }
    }
}

auto SH::Location::get_superlocation() const
-> SH::w_Location
{
    return superlocation;
}

void SH::Location::add_device(s_Device &&device)
{
    devices.push_back(std::move(device));
}

void SH::Location::add_device(s_Device &device)
{
    devices.push_back(device);
}

void SH::Location::add_location(s_Location &&location)
{
    sublocations.push_back(std::move(location));
}

void SH::Location::add_location(s_Location &location)
{
    sublocations.push_back(location);
}

void SH::Location::add_location(std::string &name)
{
    sublocations.push_back(std::make_shared<Location>(name));
}

void SH::Location::remove_device(str_view name)
{
    for (auto it = devices.begin(); it != devices.end(); it++)
    {
        if ((*it)->get_name() == name)
        {
            devices.erase(it);
            return;
        }
    }
}

void SH::Location::remove_location(str_view name)
{
    for (auto it = sublocations.begin(); it != sublocations.end(); it++)
    {
        if ((*it)->get_name() == name)
        {
            sublocations.erase(it);
            return;
        }
    }
}