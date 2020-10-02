#include "Directory.hpp"

using namespace SmartHome;

std::set< Directory > Directory::listDirectories()
{ 
    return subdirectories;
}

std::set< Device > Directory::listDevices()
{
    return {};
}

bool Directory::tryToAdd(Device)
{
    return true;
}

bool Directory::tryToAdd(Directory directory)
{
    subdirectories.insert(directory);
    return true;
}