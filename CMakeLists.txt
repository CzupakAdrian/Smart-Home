cmake_minimum_required(VERSION 3.5)

set(This CentralUnit)

project(${This} C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_compile_options(-Wall -Wextra -pedantic -Werror -frtti)

enable_testing()

add_subdirectory(googletest)

set(Headers
    DevicesContainerInterfaces.hpp
    NetworkInterfaces.hpp
    Device.hpp
    DevicesContainer.hpp
)

set(Sources
    DevicesContainer.cpp
)

include_directories(tests)
link_directories(tests)

add_library(${This} STATIC ${Sources} ${Headers})

set_target_properties(${This} PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(tests)