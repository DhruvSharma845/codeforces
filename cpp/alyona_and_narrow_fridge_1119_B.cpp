#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

bool bottlesCanBePut(int index, std::vector<int> heights, int H) {
    std::vector<int> currentHeights(heights.begin(), heights.begin() + index + 1);
    std::sort(currentHeights.begin(), currentHeights.end(), std::greater<int>());

    long long int sum = 0;
    for(int i = 0; i < currentHeights.size(); ++i) {
        if(i % 2 == 0) {
            sum += currentHeights[i];
        }
    }
    if(sum > H) {
        return false;
    }
    return true;
}

int main() {
    int N, H;
    std::cin >> N >> H;

    std::vector<int> heights(N);
    for (size_t i = 0; i < N; i++) {
        std::cin >> heights[i];
    }
    
    int low = 0, high = N - 1;
    int finalIndex = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(bottlesCanBePut(mid, heights, H) == true) {
            finalIndex = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;  
        }
    }

    std::cout << finalIndex + 1 << std::endl;
}