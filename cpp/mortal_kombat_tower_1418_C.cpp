#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

auto minimumSkipPointsToKillBosses(const std::vector<int>& bosses) -> int {
    std::vector<std::vector<int>> dpTable(2, std::vector<int>(bosses.size(), 0));

    // 0 is friend
    // 1 is you
    dpTable[0][0] = bosses[0];
    dpTable[1][0] = std::numeric_limits<int>::max() - 1;

    for(int i = 1; i < bosses.size(); ++i) {
        // calculate for friend
        int prevValue1 = dpTable[1][i-1];
        int prevValue2 = bosses[i - 1] + (i >= 2 ? dpTable[1][i-2]: 0);
        dpTable[0][i] = bosses[i] + std::min(prevValue1, prevValue2);

        // calculate for you
        dpTable[1][i] = std::min(dpTable[0][i-1], ( i >= 2 ? dpTable[0][i-2] : std::numeric_limits<int>::max()));

    }

    return std::min(dpTable[0][bosses.size() - 1], dpTable[1][bosses.size() - 1]);
}

auto main() -> int {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        int numOfbosses;
        std::cin >> numOfbosses;

        std::vector<int> bosses(numOfbosses, 0);
        for (int j = 0; j < numOfbosses; ++j) {
            int bossType;
            std::cin >> bossType;
            bosses[j] = bossType;
        }
        
        std::cout << minimumSkipPointsToKillBosses(bosses) << std::endl;
    }
    
}