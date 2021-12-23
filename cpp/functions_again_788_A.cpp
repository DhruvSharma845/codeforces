#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using lli = long long int;

auto largestSumSubarray(const std::vector<int>& arr) -> lli {
    lli max_so_far = std::numeric_limits<int>::min(), max_ending_here = 0;
 
    for (int i = 0; i < arr.size(); i++) {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

auto main() -> int {
    int N;
    std::cin >> N;

    std::vector<int> arr(N, 0);
    for(int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    std::vector<int> diffArr1(N - 1, 0);
    for(int i = 0; i < N - 1; ++i) {
        diffArr1[i] = pow(-1, i) * abs(arr[i] - arr[i+1]);
    }

    lli sum1 = largestSumSubarray(diffArr1);
    for(int i = 0; i < N - 1; ++i) {
        diffArr1[i] = - diffArr1[i];
    }
    diffArr1[0] = 0;
    lli sum2 = largestSumSubarray(diffArr1);

    std::cout << std::max(sum1, sum2) << std::endl;
    return 0;
}


/*
* 1 4   2  3 1

* 3 -2  1 -2
*   2  -1  2
*       1 -2
*          2

*/