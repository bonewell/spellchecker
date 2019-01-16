cmake_minimum_required(VERSION 2.8)
project(spellchecker)

include(GTest.cmake)
add_executable(${PROJECT_NAME} "main.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)

# Unit tests
set(TestSuite ${PROJECT_NAME}Test)
add_executable(${TestSuite}
    english.cpp
    russian.cpp
    test_language.cpp
)
target_compile_features(${TestSuite} PRIVATE cxx_std_14)

target_include_directories(${TestSuite} PRIVATE
    ${gmock_SOURCE_DIR}/include
)

target_link_libraries(${TestSuite}
    gtest
    gtest_main
)

add_test(${TestSuite} ${TestSuite})
