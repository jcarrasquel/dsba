#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

int factorial(int n) // n!
{
    return n > 1 ? n * factorial(n - 2) : 1;
}

TEST(MySuite, FactorialOK)
{
    EXPECT_EQ(120,factorial(5));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
