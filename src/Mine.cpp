#include <algorithm>
#include <iostream>
#include <vector>
#include "PrettyPrinters.h"
#include "Mine.h"

int Mine::getMaximumGold(const std::vector<std::vector<int>> & grid) {
    auto copy_grid = grid;
    return getMaximumGold(copy_grid);
}

int Mine::getMaximumGold(std::vector<std::vector<int>> & grid) {
    int mx = 0;
    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[0].size(); j++) {
            mx = std::max(mx, getMaximumGold(grid, i, j));
        }
    }

    return mx;
}

int Mine::getMaximumGold(std::vector<std::vector<int>> & grid, int i, int j) {
    const int n = grid.size();
    const int m = grid[0].size();

    if (!isvalid(i, j, n, m) || grid[i][j] == 0) {
        return 0;
    }

    const int temp = grid[i][j];
    grid[i][j] = 0;
    int mx = 0;
    for (int dir = 0; dir < 4; ++dir) {
        mx = std::max(mx, getMaximumGold(grid, i + dx[dir], j + dy[dir]));
    }

    grid[i][j] = temp;
    return mx + temp;
}

bool Mine::isvalid(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
}
