#include <gtest/gtest.h>
#include "Substituter.h"

TEST(SubstituterTest, sub) {
    ASSERT_EQ(Substituter::sub(10, 1), 9);
}
