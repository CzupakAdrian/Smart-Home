#include <vector>
#include <string_view>
namespace SH
{
// **************************************************************
template <typename getters_params_type, typename cont_type>
auto inline get_iterator_by_name(getters_params_type name, cont_type &containter)
-> typename cont_type::iterator
{
    return find_if(
        containter.begin(),
        containter.end(),
        [name](const shared_ptr<cont_type> &it){ return it->get_name() == name; }
    );
}

template <typename cont_type>
std::vector<std::string_view>
extract(const cont_type &container)
{
    vector<string_view> names;
    for(const auto& it : container)
    {
        names.push_back(it->get_name());
    }
    return move(names);
}

// FIXME This is defined automaticaly in my compiler \
but i can be not defined in other compiler

//#define get_iterator_by_name(name, container) \
    get_iterator_by_name<decltype(name), decltype(container)>(name, container)

// **************************************************************
} // namespace SH