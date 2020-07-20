#pragma once

#include "SH_Device.hpp"
#include "SH_System.hpp"
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace SH
{
    class Location: protected enable_shared_from_this<Location>
    { // TODO choose if it's better to use string_view or just string
    public: //TODO choose protection for subclass Content
    // **************************************************************************
        template <typename T>
        class Content
        {
            Content & operator=(const Content &) = delete;
            Content() = delete;
        private:
            std::vector<std::shared_ptr<T>> contents;
            std::weak_ptr<Location> superlocation;

        protected:
            Content(std::weak_ptr<Location> superlocation)
            : superlocation(std::move(superlocation))
            {}

        public:
            auto list() const;
            auto operator[](const std::string_view) const;
            void add(std::shared_ptr<T>);
            void remove(const std::string_view);
            friend class Location;
        }; // class Location::Content

    // **************************************************************************
    private:
        // Properties
        std::weak_ptr<Location> superlocation;
        Content<Location> sublocations;
        Content<Device> devices;
        Content<System> systems;
        std::string name;
    private:
        Location(std::string_view &name);
    public:
        static std::shared_ptr<Location>
            create(const std::string_view name);
        // Basic operations
        Location() = delete;
        Location &operator=(Location&) = delete;
        ~Location();
        auto get_name()             const -> std::string_view;
        void set_name(const std::string_view);
        void set_superlocation(weak_ptr<Location>);
    }; // class Location
} // namespace SH