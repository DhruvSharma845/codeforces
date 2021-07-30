#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using lli = long long int;

auto determineMinimumPenalty(int N, int M, const std::vector<int>& penalties) -> void {
    std::vector<lli> cumulativeSum(N, 0);
    cumulativeSum[0] = penalties[0];
    for (int i = 1; i < N; i++) {
        cumulativeSum[i] = penalties[i] + ((i >= M) ? cumulativeSum[i-M] : 0);
    }
    
    std::string resS{""};
    auto res = lli{0};
    for (int i = 1; i <= N; i++) {
        res += cumulativeSum[i-1];
        resS += (std::to_string(res) + " ");
    }
    std::cout << resS << std::endl;
}

auto main() -> int {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> sugarPenalty(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> sugarPenalty[i];
    }
    
    std::sort(sugarPenalty.begin(), sugarPenalty.end());

    determineMinimumPenalty(N, M, sugarPenalty);
}

/*
6 19 3 4 4 2 6 7 8
2 3 4 4 6 6 7 8 19
*/