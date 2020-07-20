#pragma once
// TODO for now it's not necessary to implement it





// TODO how to secure it from template for non FolderLike Childs

#include <memory>
#include <vector>
#include <string>
#include <string_view>


namespace SH
{
    using getters_params_type = const std::string_view &;
	template <typename T>
	using getters_return_type = std::shared_ptr<T>;

    // TODO wonder if there is need to implement template here...
    // maybe it should contain only ptrs to itself

	// TODO how to make sure, that T is derived from FolderLike

	// TODO delete assignment operators
	template<typename T>
	class Container
	{
	private:
		std::vector<std::shared_ptr<T>> contents;

	public:
		std::vector<std::string_view> list_contents() const;
		std::shared_ptr<T> operator[](getters_params_type name) const;
		void add(shared_ptr<T> new_item);
		void remove(getters_params_type name);
	};
} // namespace SH
