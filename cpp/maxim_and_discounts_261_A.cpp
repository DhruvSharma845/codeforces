#include <iostream>
#include <vector>
#include <algorithm>

auto main() -> int {
    int m;
    std::cin >> m;
    std::vector<int> discounts(m, 0);
    for (int i = 0; i < m; i++) {
        std::cin >> discounts[i];
    }

    int n;
    std::cin >> n;
    std::vector<int> prices(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }
    
    std::sort(discounts.begin(), discounts.end());
    std::sort(prices.begin(), prices.end());

    int discount = discounts[0];
    int priceIndex = prices.size() - 1;

    auto sumPrice = int{0};
    while(priceIndex >= 0) {
        int current = 0;
        while(priceIndex >= 0 && current < discount) {
            sumPrice += prices[priceIndex--]; 
            current++;
        }
        priceIndex -= 2;
    }
    std::cout << sumPrice << std::endl;
}