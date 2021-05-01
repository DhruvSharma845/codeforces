#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

typedef long long int lli;

auto calculateBeauty(int sz, std::vector<int>& elements) -> lli {
    std::sort(elements.rbegin(), elements.rend());
    lli s = 0LL;
    for (int m = 1; m <= sz; m *= 4) {
        s += std::accumulate(elements.begin(), elements.begin() + m, 0LL);
    }
    return s;
}

auto main() -> int {
    auto szMatrix = 0;
    std::cin >> szMatrix;

    std::vector<int> elements;
    elements.resize(szMatrix);

    for (auto i = 0; i < szMatrix; ++i) {
        std::cin >> elements[i];
    }
    lli finalMax = calculateBeauty(szMatrix, elements);
    std::cout << finalMax << std::endl;
} 
