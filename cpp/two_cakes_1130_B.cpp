#include <iostream>
#include <unordered_map>
#include <utility>
#include <cmath>

using lli = long long int;

auto main() -> int {
    auto tiers = int{0};
    std::cin >> tiers;

    std::unordered_map<int, std::pair<int, int>> tierSizeLocations;
    for (int i = 0; i < 2 * tiers; i++) {
        int tierSize;
        std::cin >> tierSize;
        if(tierSizeLocations.find(tierSize) == tierSizeLocations.end()) {
            tierSizeLocations.emplace(tierSize, std::make_pair(i, -1));
        }
        else {
            tierSizeLocations[tierSize].second = i;
        }
    }

    auto firstLocation = 0;
    auto secondLocation = 0;
    lli sum = 0;
    for(auto i = 1; i <= tiers; i++) {
        auto pr = tierSizeLocations[i];
        sum += abs(pr.first - firstLocation);
        sum += abs(pr.second - secondLocation);
        firstLocation = pr.first;
        secondLocation = pr.second;
    }
    std::cout << sum << std::endl;
}