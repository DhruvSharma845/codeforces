#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <functional>

using lli = long long int;

auto findMaximumHappiness(std::vector<int>& arr, std::vector<int>& wArr) -> lli {
    std::sort(arr.begin(), arr.end(), std::greater<int>());
    std::sort(wArr.begin(), wArr.end());

    lli res = 0LL;
    int i = 0;
    for(; i < wArr.size(); ++i) {
        res += static_cast<lli>(arr[i]);
    }

    for(int j = 0; j < wArr.size(); ++j) {
        if(wArr[j] == 1) {
            res += arr[j];
        }
        else {
            i = i + wArr[j] - 2;
            res += (arr[i]);
            ++i;
        }
    }
    return res;
}

auto main() -> int {
    int T;
    std::cin >> T;

    std::stringstream ss{""};
    for (int i = 0; i < T; ++i) {
        int N, K;
        std::cin >> N >> K;

        std::vector<int> arr;
        arr.reserve(N);
        for (int j = 0; j < N; ++j) {
            int x;
            std::cin >> x;
            arr.push_back(x);
        }

        std::vector<int> wArr;
        wArr.reserve(K);
        for (int m = 0; m < K; ++m) {
            int x;
            std::cin >> x;
            wArr.push_back(x);
        }
        ss << findMaximumHappiness(arr, wArr) << "\n"; 
    }

    std::cout << ss.str();
    return 0;
}