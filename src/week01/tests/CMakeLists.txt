cmake_minimum_required(VERSION 3.5)  

if(UNIT_TEST_WEEK01)
    cpmaddpackage("gh:doctest/doctest@2.4.9")                       # CPM.cmake을 사용하여 doctest 라이브러리 버전 2.4.9를 설치set(TESTS week01_test)                                          # 테스트 실행 파일의 이름을 week01_test로 설정


    add_executable(${TESTS} week01.spec.cpp)                        # week01.spec.cpp 파일을 사용하여 ${TESTS}라는 이름의 실행 파일을 생성

    target_link_libraries(${TESTS}                                  # ${TESTS} 실행 파일에 대해 doctest::doctest 및 annzy::week01 라이브러리를 링크
                            PRIVATE doctest::doctest 
                            annzy::week01)

    include(CTest)                                                  # CTest를 활성화하여 테스트 관련 기능을 사용할 수 있도록
    include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)      # doctest 라이브러리의 CMake 스크립트를 포함하여 테스트 설정을 추가
    doctest_discover_tests(${TESTS})                                # ${TESTS} 실행 파일을 doctest를 사용하여 테스트하고, 결과를 자동으로 수집
endif()
