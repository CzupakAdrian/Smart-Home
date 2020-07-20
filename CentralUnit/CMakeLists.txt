cmake_minimum_required(VERSION 3.10)

project(CentralUnit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(CentralUnit source/main.cpp)

target_include_directories(CentralUnit PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/source"
)