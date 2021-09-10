#include <iostream>
#include <utility>
#include <vector>

auto tryWithNumber(int num, const std::vector<std::pair<int, int>>& pairs) -> bool {
    int i = 1;
    for(; i < pairs.size(); i++) {
        auto& p = pairs[i];
        if(p.first != num && p.second != num) {
            break;
        }
    }

    auto& secondPair = pairs[i];
    bool res = true;
    // trying with first number
    for (int j = i + 1; j < pairs.size(); j++) {
        auto& p = pairs[j];
        if(secondPair.first != p.first && secondPair.first != p.second && num != p.first && num != p.second) {
            //std::cout << "trying with first number : " << i << " " << j << std::endl;
            res = false;
            break;
        }
    }
    
    if(res == false) {
        // trying with second number
        res = true;
        for (int j = i + 1; j < pairs.size(); j++) {
            auto& p = pairs[j];
            if(secondPair.second != p.first && secondPair.second != p.second && num != p.first && num != p.second) {
                //std::cout << "trying with second number : " << i << " " << j << std::endl;
                res = false;
                break;
            }
        }
    }
    return res;
}

auto main() -> int {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> pairs;
    pairs.reserve(M);
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;

        pairs.push_back(std::make_pair(x, y));
    }
    
    auto& firstPair = pairs[0];
    if(tryWithNumber(firstPair.first, pairs) == true) {
        std::cout << "YES" << std::endl;
        return 0;
    }
    if(tryWithNumber(firstPair.second, pairs) == true) {
        std::cout << "YES" << std::endl;
        return 0;
    }
    std::cout << "NO" << std::endl;
    return 0;
}