cmake_minimum_required(VERSION 3.5)  

if(UNIT_TEST_WEEK02)
    cpmaddpackage("gh:doctest/doctest@2.4.9")                       

    set(TESTS week02_test)                                          
    add_executable(${TESTS} week02.spec.cpp)                        

    target_link_libraries(${TESTS}                                 
                            PRIVATE doctest::doctest 
                            annzy::week02)

    include(CTest)                                                  
    include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)      
    doctest_discover_tests(${TESTS})                                
endif()