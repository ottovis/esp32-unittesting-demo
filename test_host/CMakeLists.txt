# This is the project CMakeLists.txt file for the test subproject
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)


set(EXTRA_COMPONENT_DIRS
                "../software"
                "../hardware"
                "../interface"
                "../virtuals"
                "../mocks")
                
list(APPEND EXTRA_COMPONENT_DIRS "$ENV{IDF_PATH}/tools/mocks/driver")
set(TEST_COMPONENTS "status_led gpio_hardware" CACHE STRING "List of components to test")
set(COMPONENTS main ${TEST_COMPONENTS} CACHE STRING "List of components to compile")

project(host_test)

idf_build_set_property(COMPILE_OPTIONS "-Wno-error" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wall" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-missing-field-initializers" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-fdiagnostics-color=always" APPEND)
idf_build_set_property(CXX_COMPILE_OPTIONS "-std=gnu++17" APPEND)
add_compile_definitions(UNITY_INT_WIDTH=32)
