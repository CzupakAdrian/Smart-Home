cmake_minimum_required(VERSION 3.10)

set(CMAKE_AR "C:/MinGW/bin/ar.exe")
project(SmartHome VERSION 0.0)

configure_file(Config.h.in Config.h)

add_subdirectory(CentralUnit)
#... more projects