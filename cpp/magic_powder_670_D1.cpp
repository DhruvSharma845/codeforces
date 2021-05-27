#include <iostream>
#include <vector>
#include <limits>

auto isXCookiesPossible(int X, std::vector<int>& ingdReq, std::vector<int>& currentIngd, int k) -> bool {
    for (size_t i = 0; i < ingdReq.size(); i++) {
        int currentVal = currentIngd[i] / ingdReq[i];
        if(currentVal < X) {
            int diff = ingdReq[i] * X - currentIngd[i];
            if(diff <= k) {
                k -= diff;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

auto main() -> int {
    int n, k;
    std::cin >> n >> k;

    auto sumOfIngdReq = int{0};
    std::vector<int> ingdReq(n, 0);
    for (size_t i = 0; i < n; i++){
        std::cin >> ingdReq[i];
        sumOfIngdReq += ingdReq[i];
    }

    std::vector<int> currentIngd(n , 0);
    auto minCookies = int{std::numeric_limits<int>::max()};
    auto maxCookies = int{0};
    for (size_t i = 0; i < n; i++) {
        std::cin >> currentIngd[i];
        int val = static_cast<int>(currentIngd[i] / ingdReq[i]);
        if(minCookies > val) {
            minCookies = val;
        }
        if(maxCookies < val) {
            maxCookies = val;
        }
    }
    maxCookies += (k/sumOfIngdReq + 1);

    auto res = 0;
    while(minCookies <= maxCookies) {
        auto mid = minCookies + (maxCookies - minCookies)/2;
        //std::cout << mid << std::endl;
        if(isXCookiesPossible(mid, ingdReq, currentIngd, k)) {
            res = mid;
            minCookies = mid + 1;
        }
        else {
            maxCookies = mid - 1;
        }
    }
    
    std::cout << res << std::endl;
}