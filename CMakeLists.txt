cmake_minimum_required(VERSION 3.10)

set(This SmartHome)
project(${This}
    VERSION 1.0
    DESCRIPTION "Extendable IoT System For Smart Home"
    LANGUAGES C CXX
)

add_compile_options(-Wall -Wextra -pedantic -Werror -frtti)

option(PACKAGE_TESTS "Build the tests" ON)

set(CU_INTERFACES_DIR
    include/CentralUnit/Interfaces)
file(GLOB CU_INTERFACES_HEADER CONFIGURE_DEPENDS
    "${CU_INTERFACES_DIR}/*.hpp")
add_library(CU_Interfaces_library STATIC
    ${CU_INTERFACES_HEADER})
target_include_directories(CU_Interfaces_library PUBLIC
    ${CU_INTERFACES_DIR})
set_target_properties(CU_Interfaces_library PROPERTIES
    LINKER_LANGUAGE CXX)   

set(CU_BL_INCLUDE_DIR
    include/CentralUnit/BusinesLayer)
file(GLOB CU_BL_HEADER CONFIGURE_DEPENDS
    "${CU_BL_INCLUDE_DIR}/*.hpp")
add_library(CU_BL_library STATIC
    ${CU_BL_HEADER})
target_include_directories(CU_BL_library PUBLIC
    ${CU_BL_INCLUDE_DIR})
set_target_properties(CU_BL_library PROPERTIES
    LINKER_LANGUAGE CXX) 


add_subdirectory(src)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()