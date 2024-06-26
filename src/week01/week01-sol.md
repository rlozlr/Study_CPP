---
marp: true
theme: gaia
class:
  - invert
paginate: true
---

### Some CMake Resources

- [An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/)
- https://keunjun.blog/category/cmake/
- [What's the CMake syntax to set and use variables?](https://stackoverflow.com/questions/31037882/whats-the-cmake-syntax-to-set-and-use-variables)

---

###### cpp-training-wmwoo/CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.26.0 FATAL_ERROR)

project(cpp-training-wmwoo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

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

enable_testing()
add_subdirectory(src/week01)
```

---

###### cpp-training-wmwoo/src/week01/CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.26.0 FATAL_ERROR)

add_library(week01 STATIC week01.cpp)
add_library(ctw::week01 ALIAS week01)

cmake_path(GET CMAKE_CURRENT_LIST_DIR PARENT_PATH INCLUDE_ROOT)
target_include_directories(week01
                           INTERFACE $<BUILD_INTERFACE:${INCLUDE_ROOT}>)

add_subdirectory(tests)
```

- [CMake target types](https://junstar92.tistory.com/228)
- [Generator expression on target_include_directories](https://stackoverflow.com/questions/58729233/what-is-the-use-case-for-generator-expression-on-target-include-directories)

---

###### cpp-training-wmwoo/src/week01/tests/CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.26.0 FATAL_ERROR)

cpmaddpackage("gh:doctest/doctest@2.4.9")

set(TESTS week01-test)
add_executable(${TESTS} week01.spec.cpp)

target_link_libraries(${TESTS}
    PUBLIC doctest::doctest
    ctw::week01)

include(CTest)
include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(${TESTS})
```

---

### Problem #1

```c++
auto correctStream(std::vector<std::string> const & src,
                   std::vector<std::string> const & tgt) -> std::vector<int>
{
    std::vector<int> rst;
    rst.reserve(src.size());

    std::ranges::transform(src,
                           tgt,
                           std::back_inserter(rst),
                           [](auto && s, auto && t) {
                               return s == t ? 1 : -1;
                           });

    return rst;
}
```

---

### Problem #2

```c++
auto negate(std::vector<int> const & src) -> std::vector<int>
{
    std::vector<int> rst;
    rst.reserve(src.size());

    std::ranges::transform(src, std::back_inserter(rst), [](auto && s) {
        return -s;
    });

    return rst;
}
```

---

### Problem #3

```c++
auto existsHigher(std::vector<int> const & src, int n) -> bool
{
    auto const found = std::max_element(src.begin(), src.end());

    return found != src.end() ? *found > n : false;
}
```

---

### Problem #4

```c++
auto addEnding(std::vector<std::string> const & src,
               std::string const &              sfx) -> std::vector<std::string>
{
    std::vector<std::string> rst;
    rst.reserve(src.size());

    std::ranges::transform(src, std::back_inserter(rst), [&sfx](auto && s) {
        return s + sfx;
    });

    return rst;
}
```

---

### Problem #5

```c++
auto differenceMaxMin(std::vector<int> const & src) -> int
{
    auto const [min, max] = std::ranges::minmax_element(src);
    return *max - *min;
}
```