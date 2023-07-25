add_executable(factorial_test
    factorial_test.cpp)
target_include_directories(factorial_test
    PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(factorial_test
    hello
    GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(factorial_test)