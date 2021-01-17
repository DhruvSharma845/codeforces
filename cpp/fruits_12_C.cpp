#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <queue>

std::pair<int, int> findMinMaxPriceSum(std::vector<int>& prices, const std::unordered_map<std::string, size_t>& fruits) {
    std::sort(prices.begin(), prices.end());

    using pair_t = std::pair<std::string, size_t>;
    auto cmp = [](const pair_t& a, const pair_t& b) {
        return a.second < b.second;
    };
    std::priority_queue<pair_t, std::vector<pair_t>, decltype(cmp)> que(cmp);
    for(const auto& elem: fruits) {
        que.push(elem);
    }

    int minSum = 0;
    int maxSum = 0;

    int minPriceIndex = 0;
    int maxPriceIndex = prices.size() - 1;
    while(que.empty() == false) {
        auto tp = que.top();
        que.pop();

        minSum += (prices[minPriceIndex] * tp.second);
        maxSum += (prices[maxPriceIndex] * tp.second);

        ++minPriceIndex;
        --maxPriceIndex;
    }

    return std::make_pair(minSum, maxSum);
}

int main() {
    int N, M;

    std::cin >> N >> M;

    std::vector<int> prices(N);

    for (size_t i = 0; i < N; ++i) {
        std::cin >> prices[i];
    }

    std::unordered_map<std::string, size_t> fruits;

    for (size_t i = 0; i < M; ++i) {
        std::string t;
        std::cin >> t;
        ++fruits[t];
    }

    std::pair<int, int> res = findMinMaxPriceSum(prices, fruits);
    std::cout << res.first << " " << res.second << std::endl;
    
}