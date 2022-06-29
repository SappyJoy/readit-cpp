#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

class Mine {
public:
    int getMaximumGold(const std::vector<std::vector<int>> & grid);
    int getMaximumGold(std::vector<std::vector<int>> & grid);

private:
    int getMaximumGold(std::vector<std::vector<int>> & grid, int i, int j);

    bool isvalid(int i, int j, int n, int m);

private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
};