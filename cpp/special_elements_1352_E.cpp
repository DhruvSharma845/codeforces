#include <iostream>
#include <vector>

auto getNumberOfSpecialElements(const std::vector<int>& arr) -> int {
    int numOfSpecialElements = 0;
    for (auto i = 0; i < arr.size(); ++i) {
        int l = 0;
        int r = l;

        int currentElement = arr[i];
        if(currentElement <= 1) {
            continue;
        }

        int currentSum = 0;
        bool found = false;
        while(true) {
            while(r < arr.size()) {
                currentSum += arr[r];
                ++r;
                if(l < r - 1 && currentSum == currentElement) {
                    found = true;
                    break;
                }
                if(currentSum > currentElement) {
                    break;
                } 
            }
            if(found) {
                break;
            }
            while(l <= r && currentSum > currentElement) {
                currentSum -= arr[l];
                ++l;
                if(l < r - 1 && currentSum == currentElement) {
                    found = true;
                    break;
                }
                if(currentSum < currentElement) {
                    break;
                }
            }

            if(found || r >= arr.size()) {
                break;
            }
        }
        if(found) {
            ++numOfSpecialElements;
        }
    }
    return numOfSpecialElements;
}

auto main() -> int {
    int T;
    std::cin >> T;

    for (auto i = 0; i < T; ++i) {
        int N;
        std::cin >> N;

        std::vector<int> arr(N, 0);
        for (auto j = 0; j < N; ++j) {
            int num; 
            std::cin >> num;
            arr[j] = num;
        }
        
        std::cout << getNumberOfSpecialElements(arr) << std::endl;
    }
    
    return 0;
}