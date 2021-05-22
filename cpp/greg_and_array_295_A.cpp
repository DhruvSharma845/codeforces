#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>

using lli = long long int;

auto findArrayAfterQueries(std::vector<lli>& nums, const std::vector<std::tuple<int, int, int>>& ops, const std::vector<int>& opsCount) -> std::string {
    auto currentOpsCount = lli{0};
    std::vector<lli> changeCount(nums.size(), 0);
    for (size_t i = 0; i < ops.size(); i++) {
        int start, end, d;
        std::tie(start, end, d) = ops[i];
        currentOpsCount += opsCount[i];
        auto currentOpsVal = currentOpsCount * d;
        changeCount[start - 1] += currentOpsVal;
        if(end != nums.size()) {
            changeCount[end] -= currentOpsVal;
        }
    }
    std::ostringstream oss;
    auto currentVal = lli{0};
    for(size_t i = 0; i < nums.size(); i++) {
        currentVal += changeCount[i];
        nums[i] += currentVal;
        oss << nums[i] << " ";
    }
    return oss.str();
}

auto main() -> int {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<lli> nums(n, 0);
    for (size_t i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::vector<std::tuple<int, int, int>> ops;
    ops.resize(m);
    for (size_t i = 0; i < m; i++) {
        int l, r, d;
        std::cin >> l >> r >> d;
        ops[i] = std::make_tuple(l, r, d);
    }
    
    std::vector<int> opsCount(m, 0);
    for (size_t i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        opsCount[x-1]++;
        if(y != m) {
            opsCount[y]--;
        }
    }
    std::cout << findArrayAfterQueries(nums, ops, opsCount) << std::endl;
}

/**
 *  
 * Queries:
 * 1 2
 * 1 3
 * 2 3
 * 
 * opsCount: 2 1 -1
 * 
 * Ops:
 * 1 2 1
 * 1 3 2
 * 2 3 4
 * 
 * changeCount: 8 8 -2
 */