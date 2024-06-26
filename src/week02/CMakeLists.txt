cmake_minimum_required(VERSION 3.5)  

add_library(week02 STATIC week02.cpp)                                             
add_library(annzy::week02 ALIAS week02)                                            

get_filename_component(PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)     
target_include_directories(week02 INTERFACE $<BUILD_INTERFACE:${PROJECT_ROOT}>)     

add_subdirectory(tests)                                                            
