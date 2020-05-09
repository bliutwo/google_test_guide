#include "gmock/gmock.h"

int main(int argc, char** argv) {
    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ::testing::InitGoogleMock(&argc, argv);
    // Unit test as usual, Google Mock is initialized
}
