#include <iostream>
#include <vector>
#include <algorithm>

auto hasIntersections(std::vector<int> points) -> bool {
    if(points.size() <= 2) {
        return false;
    }
    
    for (size_t i = 0; i < points.size() - 1; i++) {
        for (size_t j = i + 1; j < points.size() - 1; j++) {
            int minI = std::min(points[i], points[i+1]);
            int minJ = std::min(points[j], points[j+1]);
            int maxJ = std::max(points[j], points[j+1]);
            int maxI = std::max(points[i], points[i+1]);
            if(
                (minI < minJ && minJ < maxI && maxI < maxJ)
                || 
                (minJ < minI && minI < maxJ && maxJ < maxI) 
            ) {
                return true;
            }
        }
    }
    return false;
}

auto main() -> int {
    int N;
    std::cin >> N;
    std::vector<int> points(N, 0);
    for (size_t i = 0; i < N; i++) {
        std::cin >> points[i];
    }
    if(hasIntersections(points) == true) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "no" << std::endl;
    }
}