cmake_minimum_required(VERSION 3.10)

set(This CentralUnitTests)

file(GLOB Tests CONFIGURE_DEPENDS
    "*.cpp"
)
add_compile_options(-Wall -Wextra -pedantic -Werror -frtti)

add_subdirectory(${PROJECT_SOURCE_DIR}/extern/googletest extern/googletest)

macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE
        gtest
        gmock
        gtest_main
        SmartHomeSource
        CU_Interfaces_library
        CU_BL_library
    )
    gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(CentralUnitTest ${Tests})