#include <gtest/gtest.h>
#include "util/Adder.h"

TEST(AdderTest, sub) {
    ASSERT_EQ(Adder::add(10, 1), 11);
}
