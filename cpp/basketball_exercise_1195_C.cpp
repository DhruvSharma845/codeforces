#include <iostream>
#include <vector>
#include <algorithm>

using lli = long long int;

auto findMaxHeightOfTeam(const std::vector<int>& row1, const std::vector<int>& row2) -> lli {
    std::vector<std::vector<lli>> dpTable(3, std::vector<lli>(row1.size() + 1, 0LL));

    for(int i = 1; i <= row1.size(); ++i) {
        // [0] Including noone from any row
        dpTable[0][i] = std::max(std::max(dpTable[0][i-1], dpTable[1][i-1]), dpTable[2][i-1]);

        // [1] Including from first row if possible
        dpTable[1][i] = std::max(dpTable[0][i-1], dpTable[2][i-1]) + static_cast<lli>(row1[i-1]);

        // [2] Including from second row if possible
        dpTable[2][i] = std::max(dpTable[0][i-1], dpTable[1][i-1]) + static_cast<lli>(row2[i-1]);
    }

    return std::max(std::max(dpTable[0][row1.size()], dpTable[1][row1.size()]), dpTable[2][row1.size()]);
}

auto main() -> int {
    int N;
    std::cin >> N;

    std::vector<int> row1;
    row1.reserve(N);
    for (int i = 0; i < N; ++i) {
        int a;
        std::cin >> a;
        row1.push_back(a);
    }
    std::vector<int> row2;
    row2.reserve(N);
    for (int i = 0; i < N; ++i) {
        int b;
        std::cin >> b;
        row2.push_back(b);
    }

    std::cout << findMaxHeightOfTeam(row1, row2) << std::endl;
    
    return 0;
}