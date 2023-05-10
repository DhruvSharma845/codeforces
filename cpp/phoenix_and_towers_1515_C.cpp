#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <sstream>

using Pair = std::pair<int, int>;

auto checkIfTowersCanBeBuilt(std::vector<Pair>& heightsWithIndices, int M, int X) -> std::vector<int> {
    std::vector<int> towerIndices(heightsWithIndices.size(), 0);

    std::sort(heightsWithIndices.begin(), heightsWithIndices.end(), [](const auto& pr1, const auto& pr2) {
        if(pr1.first == pr2.first) {
            return pr1.second < pr2.second;
        }
        return pr1.first < pr2.first;
    });

    std::vector<Pair> hp;
    hp.reserve(M);
    for(int i = 0; i < M; ++i) {
        hp.push_back(std::make_pair(0, i));
    }

    auto heap_comp = [](const auto& a, const auto& b){
        return a.first > b.first;
    };

    std::make_heap(hp.begin(), hp.end(), heap_comp);

    for(int i = heightsWithIndices.size() - 1; i >= 0; --i) {
        std::pop_heap(hp.begin(), hp.end(), heap_comp);
        auto top = hp.back();
        hp.pop_back();

        top.first += heightsWithIndices[i].first;
        towerIndices[heightsWithIndices[i].second] = top.second + 1;

        hp.push_back(top);
        std::push_heap(hp.begin(), hp.end(), heap_comp);
    }

    int maxValue = 0;
    int minValue = std::numeric_limits<int>::max();
    for(const auto& pr: hp) {
        if(pr.first > maxValue) {
            maxValue = pr.first;
        }
        if(pr.first < minValue) {
            minValue = pr.first;
        }
    }

    if(maxValue - minValue <= X) {
        return towerIndices;
    }

    return std::vector<int>();
}

auto main() -> int {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        int N, M, X;
        std::cin >> N >> M >> X;
        
        std::vector<std::pair<int, int>> heightsWithIndices;
        heightsWithIndices.reserve(N);
        for (int j = 0; j < N; ++j) {
            int h;
            std::cin >> h;
            heightsWithIndices.push_back(std::make_pair(h, j));
        }

        std::vector<int> res = checkIfTowersCanBeBuilt(heightsWithIndices, M, X);
        if(res.size() == 0) {
            std::cout << "NO" << std::endl;
        }
        else {
            std::cout << "YES" << std::endl;
            std::stringstream ss{""};
            std::for_each(res.begin(), res.end(), [&ss](const auto& elem) { ss << elem << " "; });
            std::cout << ss.str() << std::endl;
        } 
    }
    return 0;
}