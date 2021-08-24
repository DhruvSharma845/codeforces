#include <iostream>
#include <unordered_map>
#include <algorithm>

auto matchPairs(std::unordered_map<int, int>& firstSocksColors,
    std::unordered_map<int, int>& secondSocksColors,
    int& first, int& second) -> void {
    for(const auto& pr: firstSocksColors) {
        if(secondSocksColors.find(pr.first) != secondSocksColors.end()) {
            int minFreq = std::min(pr.second, secondSocksColors[pr.first]);
            firstSocksColors[pr.first] -= minFreq;
            secondSocksColors[pr.first] -= minFreq;
            first -= minFreq;
            second -= minFreq;
        }
    }
}

auto transferSocks(std::unordered_map<int, int>& firstSocksColors,
    std::unordered_map<int, int>& secondSocksColors,
    int& first, int& second) -> int {
    
    int diff = (second - first) / 2;
    int cost = 0;
    for(const auto& pr: secondSocksColors) {
        if(pr.second > 1) {
            int toBeTransfered = std::min(diff, static_cast<int>(pr.second/2));
            diff -= toBeTransfered;
            secondSocksColors[pr.first] -= (toBeTransfered * 2);
            cost += toBeTransfered;
            second -= (toBeTransfered * 2);
        }
        if(diff <= 0) {
            break;
        }
    }

    if(diff > 0) {
        for(const auto& pr: secondSocksColors) {
            firstSocksColors[pr.first]++;
            secondSocksColors[pr.first]--;
            diff--;
            cost++;
            first++;
            second--;
            if(diff == 0) {
                break;
            }
        }
    }
    return cost;
}

auto findMinCostForMatching(
    std::unordered_map<int, int>& leftSocksColors,
    std::unordered_map<int, int>& rightSocksColors,
    int L, int R) -> int {

    int cost = 0;
    if(L < R) {
        matchPairs(leftSocksColors, rightSocksColors, L, R);
        cost = transferSocks(leftSocksColors, rightSocksColors, L, R);
    }
    else {
        matchPairs(rightSocksColors, leftSocksColors, R, L);
        cost = transferSocks(rightSocksColors, leftSocksColors, R, L);
    }
    cost += L;
    return cost;
}

auto main() -> int {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int N, L, R;
        std::cin >> N >> L >> R;

        std::unordered_map<int, int> leftSocks;
        std::unordered_map<int, int> rightSocks;
        for (int j = 0; j < L; j++) {
            int x;
            std::cin >> x;
            leftSocks[x]++;
        }
        for (int j = 0; j < R; j++) {
            int x;
            std::cin >> x;
            rightSocks[x]++;
        }
        std::cout << findMinCostForMatching(leftSocks, rightSocks, L, R) << std::endl;
    }
    
}
