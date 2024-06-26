---
marp: true
theme: gaia
class:
  - invert
paginate: true
---

### Solve Problems using the C++ Standard Library!


우원명

(주)볼트시뮬레이션

---

### Overview

[C++ Standard](#c-standard)
[C++ Standard Library](#c-standard-library)
[Repository Settings](#repository-settings)
[CMake Settings](#cmake-settings)
[C++ Project Settings](#c-project-settings)
[Problems](#problems)
[Constraints](#constraints)
[Marp](#marp)

---

### C++ Standard

[Where to find the current C or C++ standard documents?](https://stackoverflow.com/questions/81656/where-do-i-find-the-current-c-or-c-standard-documents)

---

### C++ Standard Library

Examples from [en.cppreference.com](https://en.cppreference.com/w/cpp/header) :
- Containers
- Algorithms

[핵심 C++ 표준 라이브러리, 2판](https://www.gilbut.co.kr/book/view?bookcode=BN003253&perdevice=pc)

---

### Repository Settings

![repo settings](./repo_settings.png)

---

### Repository Settings

[.gitignore](https://github.com/github/gitignore)

---

### Repository  Settings

[.gitattributes](https://github.com/gitattributes/gitattributes)

[Configuring Git to handle line endings](https://docs.github.com/en/get-started/getting-started-with-git/configuring-git-to-handle-line-endings)
[Is a .gitattributes file really necessary for git?](https://stackoverflow.com/questions/73086622/is-a-gitattributes-file-really-necessary-for-git)

---

### CMake Settings

[CMake Tools VSCode extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)

- [Create a CMake hello world project with CMake Quick Start](https://code.visualstudio.com/docs/cpp/cmake-quickstart)

[CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) : setup-free CMake dependency management

- [How to add CPM.cmake](https://github.com/cpm-cmake/CPM.cmake/wiki/Downloading-CPM.cmake-in-CMake)

[CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

---

### CMake Settings

(optional) .cmake-format

- https://github.com/cheshirekow/cmake_format
- [cmake-format documentation](https://cmake-format.readthedocs.io/en/latest/cmake-format.html)
- [cmake-format VSCode extension](https://marketplace.visualstudio.com/items?itemName=cheshirekow.cmake-format)
- [How to keep clean C++ codes and CMakeList file during collaboration (with vscode)](https://medium.com/@junbs95/how-to-keep-clean-c-codes-and-cmakelist-file-during-collaboration-vscode-754d8d9eb661)

---

### C++ Project Settings

![repo settings](./repo_settings.png)

---

### C++ Project Settings

.clang-format

- [C/C++ VSCode extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [Editing and Navigating C++ Code](https://code.visualstudio.com/docs/cpp/cpp-ide)
- [clang-format configurator](https://clang-format-configurator.site/)

---

### C++ Project Settings

.clang-tidy

- [C/C++ VSCode extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [Visual Studio Code C++ December 2021 Update: clang-tidy](https://devblogs.microsoft.com/cppblog/visual-studio-code-c-december-2021-update-clang-tidy/)
- [clang-tidy in Visual Studio Code](https://www.youtube.com/watch?v=8RSxQ8sluG0)

---

### C++ Project Settings

[doctest](https://github.com/doctest/doctest): C++ testing framework

CMake integration:

- [Catch2 CMake integration](https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#automatic-test-registration)
- [doctest_discover_tests()](https://github.com/doctest/doctest/blob/master/scripts/cmake/doctest.cmake)
- [include()](https://blog.naver.com/lifeisforu/222893672154)
- [how to include doctest scripts](https://github.com/doctest/doctest/issues/351#issuecomment-630554205)

---

### C++ Project Settings

Add your library 'week01' to the test project:
use [add_library()]() with STATIC

![repo settings](./repo_settings.png)

---

### Problems

```c++
//  1. Typing Game
//  Create a function that takes in two arrays: the array of user-typed words,
// and the array of correctly-typed words and outputs an array containing 1s
// (correctly-typed words) and -1s (incorrectly-typed words).
auto correctStream(std::vector<std::string> const & src,
                   std::vector<std::string> const & tgt) -> std::vector<int>;

REQUIRE_EQ(correctStream({"it", "is", "find"}, {"it", "is", "fine"}),
            std::vector<int>{1, 1, -1});
REQUIRE_EQ(correctStream({"april", "showrs", "bring", "may", "flowers"},
                            {"april", "showers", "bring", "may", "flowers"}),
            std::vector<int>{1, -1, 1, 1, 1});
REQUIRE_EQ(correctStream({"weird", "indicr", "moment"},
                            {"weird", "indict", "moment"}),
            std::vector<int>{1, -1, 1});
REQUIRE_EQ(correctStream({"starry", "wind", "skies"},
                            {"starry", "wind", "skies"}),
            std::vector<int>{1, 1, 1});
```

---

### Problems

```c++
//  2. Negate the List
//  Given a vector of integers, negate all the elements in the vector.
//  If the vector is empty, return an empty vector.
auto negate(std::vector<int> const & src) -> std::vector<int>;

REQUIRE_EQ(negate({1, 2, 3, 4}), std::vector<int>{-1, -2, -3, -4});
REQUIRE_EQ(negate({-1, -2, -3, -4}), std::vector<int>{1, 2, 3, 4});
REQUIRE_EQ(negate(std::vector<int>{}), std::vector<int>{});
```

---

### Problems

```c++
//  3. Exists a Number Higher?
//  Write a function that, given a vector of integers, returns true if
// there exists at least one number that is larger than or equal to n.
//  Return false for an empty array.
auto existsHigher(std::vector<int> const & src, int n) -> bool;

REQUIRE(existsHigher({5, 3, 15, 22, 4}, 10));
REQUIRE(existsHigher({5, 3, 15, 22, 4}, 20));
REQUIRE_FALSE(existsHigher({4, 3, 3, 3, 2, 2, 2}, 4));
REQUIRE_FALSE(existsHigher({1, 2, 3, 4, 5}, 8));
REQUIRE_FALSE(existsHigher(std::vector<int>{}, 5));
```

---

### Problems

```c++
//  4. Word Endings
//  Create a function that adds a string ending to each member in
// a vector of strings.
auto addEnding(std::vector<std::string> const & src,
               std::string const & sfx) -> std::vector<std::string>;

REQUIRE_EQ(
    addEnding({"clever", "meek", "hurried", "nice"}, "ly"),
    std::vector<std::string>{"cleverly", "meekly", "hurriedly", "nicely"});
REQUIRE_EQ(addEnding({"new", "pander", "scoop"}, "er"),
            std::vector<std::string>{"newer", "panderer", "scooper"});
REQUIRE_EQ(addEnding({"bend", "sharpen", "mean"}, "ing"),
            std::vector<std::string>{"bending", "sharpening", "meaning"});
REQUIRE_EQ(addEnding({"bend", "tooth", "mint"}, "y"),
            std::vector<std::string>{"bendy", "toothy", "minty"});
REQUIRE_EQ(addEnding({"bend", "tooth", "mint"}, "ier"),
            std::vector<std::string>{"bendier", "toothier", "mintier"});
```

---

### Problems

```c++
//  5. Difference of Max and Min Numbers in Array
//  Create a function that takes a vector of integers and returns the
// difference between the smallest and biggest numbers.
auto differenceMaxMin(std::vector<int> const & src) -> int;

REQUIRE_EQ(differenceMaxMin({10, 4, 1, 2, 8, 91}), 90);
REQUIRE_EQ(differenceMaxMin({-70, 43, 34, 54, 22}), 124);
REQUIRE_EQ(differenceMaxMin({1}), 0);
```

---

### Constraints

*Use the standard library, Luke.*

![use the force](./jayblixt-jay-skywalker.gif)
*image from [tenor.com](https://tenor.com/)*

---

### Marp

[Marp](https://marp.app/) : markdown presentation ecosystem

---

### 감사합니다:smile: