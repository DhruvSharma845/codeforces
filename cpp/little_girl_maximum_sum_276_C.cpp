#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <utility>
#include <functional>

using lli = long long int;

auto findMaximumSumForQueries(
    const std::vector<int>& elements,
    std::vector<int>& prefix
) -> lli {
    
    for(auto i = 1; i < elements.size(); ++i) {
        prefix[i] += prefix[i - 1];
    }

    std::sort(prefix.begin(), prefix.end());

    lli totalSum = 0;
    for(auto i = 0; i < elements.size(); ++i) {
        totalSum += (static_cast<lli>(elements[i]) * static_cast<lli>(prefix[i]));
    }

    return totalSum;
}

auto main() -> int {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> elements(N, 0);
    for (auto i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        elements[i] = num;
    }

    std::sort(elements.begin(), elements.end());

    std::vector<int> prefix(N, 0);
    for (auto i = 0; i < Q; ++i) {
        int l, r;
        std::cin >> l >> r;
        prefix[l - 1]++;
        if(r < N) {
            prefix[r]--;
        }
    }

    std::cout << findMaximumSumForQueries(elements, prefix) << std::endl;
    
    return 0;
}