#include <iostream>
#include <vector>
#include <algorithm>

using lli = long long int;

auto findMaximumPossibleMedian(std::vector<int>& arr, int K) -> lli {
    std::sort(arr.begin(), arr.end());
    
    lli low = 0;
    lli high = (*std::max_element(arr.begin(), arr.end())) + K;

    int res = 0;
    while(low <= high) {
        lli mid = low + (high - low) / 2;

        // if possible with mid
        int currentOps = 0;
        bool isPossible = true;
        for(int i = arr.size() / 2; i < arr.size(); ++i) {
            if(mid - arr[i] > 0) {
                currentOps += mid - arr[i];
                if(currentOps > K) {
                    isPossible = false;
                    break;
                }
            }
        }
        if(isPossible == true) {
            res = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return res;
}

auto main() -> int {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> arr;
    arr.reserve(N);
    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        arr.push_back(x);
    }

    std::cout << findMaximumPossibleMedian(arr, K) << std::endl;
    
    return 0;
}



/*
// could be another approach to try
if(K == 0) {
        return arr[arr.size() / 2];
    }
    int currentIndexValue = arr[arr.size() / 2];
    for(int i = (arr.size() / 2) + 1; i < arr.size(); ++i) {
        int distance = i - (arr.size() / 2);
        int diff = arr[i] - currentIndexValue;
        if(K >= (distance * diff)) {
            currentIndexValue = arr[i];
            K -= (distance * diff);
        }
        else {
            K = 0;
            currentIndexValue += (K / distance);
        }
        if(K == 0) {
            break;
        }
    }
    // K is still remaining
    if(K > 0) {
        currentIndexValue += (K / static_cast<int>((arr.size()/2) + 1));
    }
    return currentIndexValue;
*/
