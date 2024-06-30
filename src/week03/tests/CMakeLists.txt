cmake_minimum_required(VERSION 3.5)

if(UNIT_TEST_WEEK03)
    cpmaddpackage("gh:doctest/doctest@2.4.9")

    set(TESTS week03_test)
    add_executable(${TESTS} week03.spec.cpp)

    target_link_libraries(${TESTS}                                 
                            PRIVATE doctest::doctest 
                            annzy::week03)

    include(cTest)
    include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
    doctest_discover_tests(${TESTS})
endif()

