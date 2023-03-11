#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

auto findMinimumDays(std::vector<std::pair<int, int>>& days) -> int {
    std::sort(days.begin(), days.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if(a.first != b.first) {
            return a.first < b.first;
        }
        else {
            return a.second < b.second;
        }
    });

    int currentMinLimit = 0;
    for(int i = 0; i < days.size(); ++i) {
        if(days[i].second >= currentMinLimit) {
            currentMinLimit = days[i].second;
        }
        else {
            currentMinLimit = days[i].first;
        }
    }
    return currentMinLimit;
}


auto main() -> int {
    auto exams = 0;
    std::cin >> exams;

    auto days = std::vector<std::pair<int, int>>();
    days.reserve(exams);
    for (auto i = 0; i < exams; ++i) {
        auto originalDay = 0;
        auto earlyDay = 0;
        std::cin >> originalDay >> earlyDay;
        days.emplace_back(originalDay, earlyDay);
    }
    
    std::cout << findMinimumDays(days) << std::endl;
}
