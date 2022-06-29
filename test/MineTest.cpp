#include <gtest/gtest.h>
#include "Mine.h"

TEST(Path_with_Maximum_Gold, Test1) {
    Mine mine;
    std::vector<std::vector<int>> grid = {{ 0, 6, 0},
                                          { 5, 8, 7},
                                          { 0, 9, 0}};

    const int ans = mine.getMaximumGold(grid);
    ASSERT_EQ(24, ans) << "Input: " << ::testing::PrintToString(grid);
}