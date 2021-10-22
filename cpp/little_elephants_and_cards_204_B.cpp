#include <iostream>
//#include <vector>
//#include <utility>
#include <unordered_map>
#include <queue>
#include <algorithm>

using PQElementType = std::pair<int, int>;

auto main(int argc, char* argv[]) -> int {
    int N;
    std::cin >> N;

    int half = N % 2 == 0 ? (N/2) : (N/2) + 1;
    //std::cout << "Half: " << half << std::endl;

    std::unordered_map<int, int> frontFreq;
    std::unordered_map<int, int> backFreq;
    for (int i = 0; i < N; ++i) {
        int f, s;
        std::cin >> f >> s;
        frontFreq[f]++;
        if(f != s) {
            backFreq[s]++;
        }
    }

    auto comparator = [](PQElementType& a, PQElementType& b) {
        return a.first < b.first;
    };
    std::priority_queue<PQElementType, std::vector<PQElementType>, decltype(comparator)> frontPQ(comparator);

    for(const auto& p: frontFreq) {
        frontPQ.emplace(p.second, p.first);
    }

    int cardsToBeTurned =  -1;
    while(!frontPQ.empty()) {
        const auto t = frontPQ.top();
        frontPQ.pop();

        auto quantityFront = t.first;
        //std::cout << "Front: " << quantityFront << " Second: " << t.second << std::endl;
        auto quantityBack = int{0};
        if(backFreq.find(t.second) != backFreq.end()) {
            quantityBack += backFreq[t.second];
        }
        if(quantityFront + quantityBack >= half) {
            cardsToBeTurned = quantityFront > half ? 0 : half - quantityFront;
            break;
        }
    }

    if(cardsToBeTurned != -1) {
        std::cout << cardsToBeTurned << std::endl;
        return 0;
    }

    // if not found in front facing
    int maxBack = 0;
    for(const auto& p: backFreq) {
        maxBack = std::max(maxBack, p.second);
    }
    if(maxBack >= half) {
        std::cout << half << std::endl;
        return 0;
    }
    std::cout << "-1" << std::endl;
    return 0;
}