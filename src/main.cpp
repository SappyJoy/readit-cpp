
#include "Mine.h"
#include "PrettyPrinters.h"
#include <iostream>
#include <vector>

int main() {
    Mine mine;
    std::vector<std::vector<int>> grid = {{ 0, 6, 0},
                                          { 5, 8, 7},
                                          { 0, 9, 0}};

    const int ans = mine.getMaximumGold(grid);
    std::cout << ans << "\n";
    return 0;
}