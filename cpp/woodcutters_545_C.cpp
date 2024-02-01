#include <iostream>
#include <vector>
#include <utility>
#include <limits>

auto findMaxTreesThatCanFell(const std::vector<std::pair<int, int>>& trees) -> int {
    //int currentMaxOccupied = trees[0].first;
    int currentMaxOccupied = std::numeric_limits<int>::min();
    int maxTrees = 0;
    for(int i = 0; i < trees.size(); ++i) {
        std::pair<int, int> tree = trees[i];
        if((tree.first - tree.second) > currentMaxOccupied) {
            currentMaxOccupied = tree.first;
            ++maxTrees;
        }
        else if((i == trees.size() - 1) || (i < trees.size() - 1 && tree.first + tree.second < trees[i + 1].first)){
            currentMaxOccupied = tree.first + tree.second;
            ++maxTrees;
        }
        else {
            currentMaxOccupied = tree.first;
        }
    }
    return maxTrees;
}

auto main() -> int {
    int T;
    std::cin >> T;

    std::vector<std::pair<int, int>> trees(T, std::pair<int, int>());
    for (auto i = 0; i < T; ++i) {
        int c, h;
        std::cin >> c >> h;
        trees[i].first = c;
        trees[i].second = h;
    }

    std::cout << findMaxTreesThatCanFell(trees) << std::endl;
    
    return 0;
}