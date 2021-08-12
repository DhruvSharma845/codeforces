#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using lli = long long int;

auto minimumCostOfPath(const std::vector<int>& costs) -> lli {
    int N = costs.size();
    lli oddSum = 0, evenSum = costs[0];
    int oddMin = std::numeric_limits<int>::max(), evenMin = costs[0];
    int cntOdd = 0, cntEven = 1;

    lli minCost = std::numeric_limits<lli>::max();
    for (int i = 1; i < N; i++) {
        if(i % 2 != 0) {
            oddMin = std::min(oddMin, costs[i]);
        }
        else {
            evenMin = std::min(evenMin, costs[i]); 
        }
        lli cost = oddSum + evenSum + (static_cast<lli>(oddMin) * (N - cntOdd)) + (static_cast<lli>(evenMin) * (N - cntEven));
        minCost = std::min(minCost, cost);
        if(i % 2 != 0) {
            oddSum += costs[i];
            cntOdd++;
        }
        else {
            evenSum += costs[i];
            cntEven++;
        }
    }
    return minCost;
}

auto main() -> int {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        std::cin >> N;
        std::vector<int> costs(N, 0);
        for (int j = 0; j < N; j++) {
            std::cin >> costs[j];
        }
        
        std::cout << minimumCostOfPath(costs) << std::endl;
    }
}