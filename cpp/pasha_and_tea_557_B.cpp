#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> 

auto main() -> int {
    int N, W;
    std::cin >> N >> W;

    std::vector<int> cupCaps(2*N, 0);
    for (int i = 0; i < 2 * N; i++) {
        std::cin >> cupCaps[i];
    }

    std::sort(cupCaps.begin(), cupCaps.end());
    
    double limitCap = static_cast<double>(W) / (3 * N);
    //std::cout << limitCap << std::endl;
    if(limitCap < cupCaps[0] && (2 * limitCap) < cupCaps[cupCaps.size() / 2]) {
        std::cout << std::setprecision(10) << (3 * N * limitCap) << std::endl;
    }
    else {
        double newLimitCap = std::min(static_cast<double>(cupCaps[0]), static_cast<double>(cupCaps[cupCaps.size() / 2]) / 2);
        std::cout << std::setprecision(10) << (3 * N * newLimitCap) << std::endl;
    }
}