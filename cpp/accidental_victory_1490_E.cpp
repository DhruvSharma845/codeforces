#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>

using lli = long long int;

auto findPossibleWinners(std::vector<std::pair<int, int>>& elementsWithIndices, lli sum) -> std::vector<int> {
        
    using Pair = std::pair<int, int>;
    std::sort(elementsWithIndices.begin(), elementsWithIndices.end(), [](const Pair& a, const Pair& b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    std::vector<int> res;
    for(int i = elementsWithIndices.size() - 1; i >= 0; --i) {
        sum -= elementsWithIndices[i].first;
        res.push_back(elementsWithIndices[i].second + 1);
        if(sum < elementsWithIndices[i].first) {
            break;
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

auto main() -> int {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        std::cin >> N;

        std::vector<std::pair<int, int>> elementsWithIndices;
        elementsWithIndices.reserve(N);

        lli sum = 0LL;
        for (int j = 0; j < N; ++j) {
            int x;
            std::cin >> x;
            sum += x;
            elementsWithIndices.emplace_back(x, j);
        }

        auto winners = findPossibleWinners(elementsWithIndices, sum);
        std::cout << winners.size() << std::endl;
        std::stringstream ss;
        for(const auto& elem: winners) {
            ss << elem << " ";
        }
        std::cout << ss.str() << std::endl;
    }
    
    return 0;
}