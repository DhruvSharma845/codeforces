#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

auto findInconvenience(int N, int M, std::vector<std::pair<int, int>>& sightsWithPosition) -> int {
    std::sort(sightsWithPosition.begin(), sightsWithPosition.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        else {
            return a.first < b.first;
        }
    });
    /*std::for_each(sightsWithPosition.begin(), sightsWithPosition.end(), [](const std::pair<int, int>& a) {
        std::cout << a.first << " " << a.second << std::endl;
    });

    1 2 3 4 5 6 7 8 9
    2 4 4 1 1 1 1 1 2
    
    Increasing order: 4 5 6 7(1) 8(2) 1(3) 9 2 3
    1(3) 7(1) 8(2)

    Decreasing order: 2 3 1 9 4 5 6 7 8
    
    */
   int totalInconv = 0;
    for(int i = 0; i < N; ++i) {
        int iM = i * M;
        // sort the subarray
        auto endIt = (i == N -1) ? sightsWithPosition.end() : sightsWithPosition.begin() + ((i + 1) * M);
        std::sort(sightsWithPosition.begin() + iM, endIt, [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        });

        std::vector<int> sortedElements;
        for(int j = 0; j < M; ++j) {
            sortedElements.push_back(sightsWithPosition[iM + j].first);
            std::sort(sortedElements.begin(), sortedElements.end());
            /*std::for_each(sortedElements.begin(), sortedElements.end(), [](const int& a) {
                std::cout << a << std::endl;
            });
            std::cout << std::endl;*/
            auto lowerBound = std::lower_bound(sortedElements.begin(), sortedElements.end(), sightsWithPosition[iM + j].first);
            totalInconv += (lowerBound - sortedElements.begin());
        }
    }
    return totalInconv;
}

auto main() -> int {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        int N, M;
        std::cin >> N >> M;

        std::vector<std::pair<int, int>> sightWithPosition;
        sightWithPosition.reserve(N * M);
        for (int j = 0; j < N * M; ++j) {
            int s;
            std::cin >> s;
            sightWithPosition.emplace_back(s, j + 1);
        }
        std::cout << findInconvenience(N, M, sightWithPosition) << std::endl;
    }
    
}