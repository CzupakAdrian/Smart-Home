cmake_minimum_required(VERSION 3.5)

set(This CentralUnitTests)

set(Sources
    test.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    CentralUnit
)

add_test(
    NAME ${This}
    COMMAND ${This}
)