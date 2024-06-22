cmake_minimum_required(VERSION 3.5)  

add_library(week01 STATIC week01.cpp)                                               # week01.cpp를 사용해서 static lib week01 생성
add_library(annzy::week01 ALIAS week01)                                             # week01 별칭을 annzy:week01로 정의

get_filename_component(PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)     # PROJECT_ROOT 변수에 현재 CMakeLists.txt 파일이 있는 디렉토리의 부모 디렉토리 경로를 절대 경로로 저장
target_include_directories(week01 INTERFACE $<BUILD_INTERFACE:${PROJECT_ROOT}>)     # week01 타겟에 대해 빌드 인터페이스로 PROJECT_ROOT 디렉토리를 포함

add_subdirectory(tests)                                                             # tests 디렉토리에 있는 하위 프로젝트를 추가