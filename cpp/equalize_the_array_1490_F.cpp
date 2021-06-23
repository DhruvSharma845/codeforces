#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

auto equalizeArray(std::unordered_map<int, int>& freq, int N) -> int {
    
    std::map<int, int> freqCount;
    for(const auto& pr: freq) {
        freqCount[pr.second]++;
    }
    
    auto minRemovals = N;
    int uniqueRemaining = freq.size();
    for(const auto& pr: freqCount) {
        int currentRemovals = N - (uniqueRemaining * pr.first);
        if(currentRemovals < minRemovals) {
            minRemovals = currentRemovals;
        }
        uniqueRemaining -= pr.second;
    }
    return minRemovals;
}

auto main() -> int {
    int T;
    std::cin >> T;

    for (auto i = 0; i < T; i++) {
        int N;
        std::cin >> N;
        std::unordered_map<int, int> freq;
        for (auto j = 0; j < N; j++) {
            int x;
            std::cin >> x;
            freq[x]++;
        }
        std::cout << equalizeArray(freq, N) << std::endl;
    }
}