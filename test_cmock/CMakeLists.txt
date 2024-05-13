# This is the project CMakeLists.txt file for the test subproject
cmake_minimum_required(VERSION 3.16)


set(COMPONENTS main)
set(EXTRA_COMPONENT_DIRS
                "../software"
                "../interface"
                "../virtuals"
                "../mocks")
    
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
include_directories(${CMAKE_SOURCE_DIR}/config)

list(APPEND EXTRA_COMPONENT_DIRS "$ENV{IDF_PATH}/tools/mocks/freertos/")
set(TEST_COMPONENTS "status_led" CACHE STRING "List of components to test")

project(host_test)

idf_build_set_property(COMPILE_OPTIONS "-Wno-error" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wall" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-missing-field-initializers" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-fdiagnostics-color=always" APPEND)
idf_build_set_property(CXX_COMPILE_OPTIONS "-std=gnu++17" APPEND)


