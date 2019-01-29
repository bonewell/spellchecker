cmake_minimum_required(VERSION 2.8)
project(spellchecker)

include(GTest.cmake)
add_executable(${PROJECT_NAME}
    main.cpp
    language_list.cpp
    english/english.cpp
    english/keep_letter_e.cpp
    russian/russian.cpp
    russian/vowel_after_sizzling.cpp
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
)

# Unit tests
enable_testing()

set(TestSuite ${PROJECT_NAME}Test)
add_executable(${TestSuite}
    english/english.cpp
    english/keep_letter_e.cpp
    english/test_english.cpp
    russian/russian.cpp
    russian/vowel_after_sizzling.cpp
    russian/test_russian.cpp
)
target_compile_features(${TestSuite} PRIVATE cxx_std_14)

target_include_directories(${TestSuite} PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${gmock_SOURCE_DIR}/include
)

target_link_libraries(${TestSuite}
    gtest
    gtest_main
    gmock
    gmock_main
)

add_test(${TestSuite} ${TestSuite})
