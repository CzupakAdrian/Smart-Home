cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "C:/Users/czupa/scoop/apps/gcc/9.3.0-1/bin/g++.exe")
set(CMAKE_C_COMPILER "C:/Users/czupa/scoop/apps/gcc/9.3.0-1/bin/gcc.exe")
set(CMAKE_AR "C:/Users/czupa/scoop/apps/gcc/9.3.0-1/bin/ar.exe")
project(SmartHome VERSION 0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

enable_testing()

configure_file(Config.h.in Config.h)

add_subdirectory(CentralUnit)
add_subdirectory(googletest)
#... more projects