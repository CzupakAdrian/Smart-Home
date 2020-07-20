#include "SH_Location.hpp"
#include "SH_lib.cpp"

using namespace std;

using SH::Location;
using SH::Device;
using SH::System;
using SH::extract;

std::shared_ptr<Location>
Location::create(const std::string_view name)
{
    return make_shared<Location>(name);
}

// **************************************************************************
Location::Location(string_view &name)
: name(name)
, sublocations(weak_from_this())
, devices(weak_from_this())
, systems(weak_from_this())
{}

// **************************************************************************
Location::~Location()
{
    // TODO it should ask if user wants to remove existing systems
    // or to transport them to superlocation or whatever
}

// **************************************************************************
string_view Location::get_name() const
{
    return name;
}

// **************************************************************************
void Location::set_name(const string_view new_name)
{
    name = new_name;
}

void Location::set_superlocation(weak_ptr<Location> new_superlocation)
{
    superlocation = new_superlocation;
}

// **************************************************************************
//              Location::Content methods
// **************************************************************************

// **************************************************************************
template <typename T> auto inline
Location::Content<T>::list() const
{
    return extract(contents);
}
// **************************************************************************
template <typename T> auto inline
Location::Content<T>::operator[](const string_view name) const
{
    return *get_iterator_by_name(name, contents);
}

// **************************************************************************
template <typename T> void inline
Location::Content<T>::add(shared_ptr<T> new_item)
{
    new_item->set_superlocation(superlocation);
    contents.push_back(move(new_item));
}

// **************************************************************************
// TODO secure removers from removing when for example device is being used by some system
template <typename T> void inline
Location::Content<T>::remove(const string_view name)
{
    contents.erase(get_iterator_by_name(name, contents));
}