#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(TasteCaseName, UnitTestName) {
    // Unit test here
}

int main(int argc, char** argv) {
    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ::testing::InitGoogleMock(&argc, argv);
    // Unit test as usual, Google Mock is initialized
}
