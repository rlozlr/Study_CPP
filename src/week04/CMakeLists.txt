cmake_minimum_required(VERSION 3.5)

add_library(week04 STATIC week04.cpp)
add_library(annzy::week04 ALIAS week04)

get_filename_component(PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
target_include_directories(week04 INTERFACE $<BUILD_INTERFACE:${PROJECT_ROOT}>)

add_subdirectory(tests)