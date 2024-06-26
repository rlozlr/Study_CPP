cmake_minimum_required(VERSION 3.5)                 # 최대한 높은 버전 사용
project(STL_EDU_ANZY VERSION 0.1.0)                 # 프로젝트 이름과 버전


# # # https://github.com/llvm/llvm-project/releases/tag/llvmorg-18.1.6 여기서 .exe 다운로드
# set(CMAKE_CXX_COMPILER "C:/LLVM/bin/clang++.exe")   # Clang 컴파일러 설정
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)                          # C++ 표준 설정
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)               # C++ 표준 준수를 필수로 설정


# CPM.cmake settings
# ------------------------------------------------------------------------------
file(
  DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)
# ------------------------------------------------------------------------------

# unit test 제어 option(변수명 "설명(필수아님)"" ON/OFF)
option(UNIT_TEST_WEEK01 "Build week01 tests" OFF)
option(UNIT_TEST_WEEK02 "Build week02 tests" OFF)
option(UNIT_TEST_WEEK03 "Build week03 tests" OFF)

enable_testing()                                    # 테스팅을 활성화
add_subdirectory(src/week01)                        # src/week01 dir에서 하위 프로젝트 추가
add_subdirectory(src/week02)
add_subdirectory(src/week03)