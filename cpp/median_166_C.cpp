#include <iostream>
#include <vector>
#include <algorithm>

auto findMinElementsToBeAdded(std::vector<int>& arr, int x) -> int {
    std::sort(arr.begin(), arr.end());

    int midIndex = (static_cast<int>(arr.size()) + 1)/2 ;
    
    if(arr[midIndex - 1] == x) {
        return 0;
    }

    auto estimatedIndex = std::lower_bound(arr.begin(), arr.end(), x);

    if(estimatedIndex == arr.end()) {
        return static_cast<int>(arr.size()) + 1;
    }
    else {
        if(*estimatedIndex != x) {
            int leftCount = estimatedIndex - arr.begin();
            int rightCount = arr.size() - leftCount;
            return (rightCount > leftCount) ? (rightCount - leftCount): (leftCount - rightCount + 1);
        }
        else {
            auto estimatedUpperBound = std::upper_bound(arr.begin(), arr.end(), x);
            int lowerLeftCount = estimatedIndex - arr.begin();
            int lowerRightCount = arr.size() - 1 - lowerLeftCount;
            int lowerResult = (lowerRightCount > lowerLeftCount) ? (lowerRightCount - lowerLeftCount - 1): (lowerLeftCount - lowerRightCount);
            if(estimatedIndex + 1 == estimatedUpperBound) {
                return lowerResult;
            }
            else {
                auto upperBound = estimatedUpperBound - 1;

                int upperLeftCount = upperBound - arr.begin();
                int upperRightCount = arr.size() - 1 - upperLeftCount;
                int upperResult = (upperRightCount > upperLeftCount) ? (upperRightCount - upperLeftCount - 1): (upperLeftCount - upperRightCount);

                return std::min(lowerResult, upperResult);
            }
        }
    }
    return 0;
}

auto main() -> int {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    std::cout << findMinElementsToBeAdded(arr, x) << std::endl;
}