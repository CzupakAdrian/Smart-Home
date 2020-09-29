set(This SmartHomeSource)

add_compile_options(-Wall -Wextra -pedantic -Werror -frtti)

file(GLOB SH_SOURCE CONFIGURE_DEPENDS
    "*.cpp"
)

add_library(${This}
    ${SH_SOURCE}
)

target_link_libraries(${This} PRIVATE
    CU_Interfaces_library
    CU_BL_library
)

target_compile_features(${This} PUBLIC cxx_std_11)
