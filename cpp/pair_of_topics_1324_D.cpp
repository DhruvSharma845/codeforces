#include <iostream>
#include <vector>
#include <algorithm>


auto findGoodPairs(std::vector<int>& diffs) -> long long int {
    std::sort(diffs.begin(), diffs.end());

    long long int sum = 0;
    for(int i = 0; i < diffs.size(); ++i) {
        //std::cout << diffs[i] << std::endl;
        if(diffs[i] > 0) {
            sum += (diffs.size() - (i + 1));
        }
        else {
            int low = i;
            int high = diffs.size();
            int index = -1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(diffs[mid] + diffs[i] > 0) {
                    index = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            if(index != -1) {
                sum += (diffs.size() - index);
            }
        }
    }
    return sum;
}

auto main() -> int {
    int N;
    std::cin >> N;

    std::vector<int> a;
    a.reserve(N);

    for(int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }

    std::vector<int> diffs;
    diffs.reserve(N);

    for(int i = 0; i < N; ++i) {
        int b;
        std::cin >> b;
        diffs.push_back(a[i]-b);
    }
    std::cout << findGoodPairs(diffs) << std::endl;
    return 0;
}