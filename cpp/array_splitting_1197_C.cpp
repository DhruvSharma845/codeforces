#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <utility>

auto findMinCostOnSplittingInK(const std::vector<int> nums, int K) -> int {
    if(K == 1) {
        return (nums[nums.size() - 1] - nums[0]);
    }
    std::vector<std::pair<int, int>> diff;
    for (size_t i = 1; i < nums.size(); i++) {
        diff.push_back(std::make_pair(nums[i] - nums[i-1], i-1));
    }
    
    std::nth_element(diff.begin(), diff.begin() + K - 2, diff.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first > b.first;
    });

    auto sum = nums[nums.size() - 1] - nums[0];
    for(size_t i = 0; i < K - 1; i++) {
        sum -= diff[i].first;
    }
    return sum;
}

auto main() -> int {
    auto N = int{0};
    auto K = int{0};
    std::cin >> N >> K;
    std::vector<int> nums;
    nums.resize(N);
    for (auto i = 0; i < N; i++) {
        std::cin >> nums[i];
    }
    std::cout << findMinCostOnSplittingInK(nums, K);

}

