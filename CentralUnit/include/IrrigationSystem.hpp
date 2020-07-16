#pragma once

#include "System.hpp"
#include <memory>
#include <string>
#include <vector>

namespace SH::Systems
{
    class IrrigationSystem: public System
    {
    public:
        class Section: public System
        {
        protected:
            Section();
            
        };
    private:
        // TODO just think if it's possible to do some derriviation
        // cuz Systems can have subsystems just as Locations ...
        
    public:
        IrrigationSystem();
        ~IrrigationSystem();

        // TODO new section should add a section to irrigation system
        shared_ptr<Section> new_section(const string &name) [[nodiscard]];
    };
} // namespace SH
