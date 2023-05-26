#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using lli = long long int;

auto findMaxBeautyOfJourney(const std::vector<int>& beauties) -> lli {
    
    std::unordered_map<int, lli> diffMap;

    lli totalMax = 0L;
    for(int i = 0; i < beauties.size(); ++i) {
        int diff = beauties[i] - i;
        diffMap[diff] += beauties[i];
        if(diffMap[diff] > totalMax) {
            totalMax = diffMap[diff];
        }
    }
    return totalMax;
}

auto main() -> int {
    int N;
    std::cin >> N;

    std::vector<int> beauties(N, 0);
    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        beauties[i] = x;
    }

    std::cout << findMaxBeautyOfJourney(beauties) << std::endl;
    
    return 0;
}