#include "ComponentsTree.hpp"

using namespace SmartHome;

std::set< Component > ComponentsTree::listComponents() 
{
    return components;
}

bool ComponentsTree::tryToAddDirectory(Directory, Name name) 
{
    components.insert(Directory{name});
    return true;
}