#pragma once

#include "Device.hpp"
#include "System.hpp"
#include <memory>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

namespace SH
{
    using getters_params_type = const string_view &;

    class Location
    { // TODO choose if it's better to use string_view or just string
    private:
        // Properties
        weak_ptr<Location> superlocation;
        vector<shared_ptr<Location>> sublocations;
        vector<shared_ptr<Device>> devices;
        vector<shared_ptr<System>> systems;
        string name;
        template <typename cont_type>
        auto static get_iterator_by_name(getters_params_type, cont_type &) -> cont_type::iterator;

    public:

        // Basic operations
        Location() = delete;
        Location(string &name);
        Location &operator=(Location&) = delete;
        ~Location();
        auto get_name()             const -> string_view;
        void change_name(const string &new_name);

        // Extractors
        auto extract_devices()      const -> vector<string_view>;
        auto extract_sublocations() const -> vector<string_view>;
        auto extract_systems()      const -> vector<string_view>;

        // Getters
        auto get_device(getters_params_type name)
                                          -> weak_ptr<Device>;
        auto get_sublocation(getters_params_type name)
                                          -> weak_ptr<Location>;
        auto get_system(getters_params_type name)
                                          -> weak_ptr<System>;
        auto get_superlocation()    const -> weak_ptr<Location>;

        // Adders
        void add_device(shared_ptr<Device> &&new_device);
        //void add_device(shared_ptr<Device> &device); // is it necessary?
        void add_location(shared_ptr<Location> &&new_location);
        //void add_location(shared_ptr<Location> &location); // is it necessary?
        void add_location(const string &name); // TODO decide what type to pass
        void add_system(shared_ptr<System> &&new_system);

        // Removers
        void remove_location(getters_params_type name);
        void remove_device(getters_params_type name);
        void remove_system(getters_params_type name);
    };
} // namespace SH