cmake_minimum_required(VERSION 3.10)
set(gccBinPath "C:/Users/czupa/scoop/apps/gcc/9.3.0-1/bin")
set(CMAKE_CXX_COMPILER "${gccBinPath}/g++.exe")
set(CMAKE_C_COMPILER "${gccBinPath}/gcc.exe")
set(CMAKE_AR "${gccBinPath}/ar.exe")
project(SmartHome)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

configure_file(Config.h.in Config.h)

add_subdirectory(CentralUnit)
add_subdirectory(googletest)
#... more projects