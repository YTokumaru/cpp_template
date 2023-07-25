#include <stdexcept>
#include "gtest/gtest.h"
#include "hello.hpp"

// Run tests with ctest

TEST(factorialtest, BasicAssersions) {
  EXPECT_EQ(factorial(0), 1);
  EXPECT_EQ(factorial(1), 1);
  EXPECT_EQ(factorial(2), 2);
  EXPECT_EQ(factorial(3), 6);
  EXPECT_EQ(factorial(10), 3628800);
}

// This test fails
TEST(factorialtest, Negative) {
  EXPECT_THROW(factorial(-10), std::invalid_argument);
}