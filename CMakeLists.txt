# This is the project CMakeLists.txt file for the test subproject
cmake_minimum_required(VERSION 3.16)

set(EXTRA_COMPONENT_DIRS
                "software"
                "interface"
                "virtuals"
                "hardware")
    

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
include_directories(${CMAKE_SOURCE_DIR}/config)
project(testing_demo)

idf_build_set_property(COMPILE_OPTIONS "-Wno-error" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wall" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-missing-field-initializers" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-fdiagnostics-color=always" APPEND)
idf_build_set_property(CXX_COMPILE_OPTIONS "-std=gnu++17" APPEND)

