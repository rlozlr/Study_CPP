cmake_minimum_required(VERSION 3.5)

add_library(week03 STATIC week03.cpp)
add_library(annzy::week03 ALIAS week03)

get_filename_component(PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
target_include_directories(week03 INTERFACE $<BUILD_INTERFACE:${PROJECT_ROOT}>)

add_subdirectory(tests)