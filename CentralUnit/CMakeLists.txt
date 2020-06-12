cmake_minimum_required(VERSION 3.10)

project(CentralUnit VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_executable(CentralUnit main.cpp)

target_include_directories(CentralUnit PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/include"
)