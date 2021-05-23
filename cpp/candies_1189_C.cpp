#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

auto main() -> int {
    int n;
    std::cin >> n;

    std::vector<int> nums(n, 0);
    for (size_t i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::vector<int> sums(n, 0);
    sums[0] = nums[0];
    for (size_t i = 1; i < n; i++) {
        sums[i] = nums[i] + sums[i-1];
    }
    
    int q;
    std::cin >> q;
    for (size_t i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        auto candies = (sums[r - 1] - (l == 1 ? 0: sums[l-2])) / 10;
        std::cout << candies << std::endl;
    }
    
}


/*
8  7  3   1   7   0   9   4
8 15  18  19  26  26  35  39


*/