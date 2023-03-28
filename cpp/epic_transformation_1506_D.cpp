#include <iostream>
#include <vector>
#include <map>
#include <limits> 

auto main() -> int {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        std::cin >> N;
        // using map is necessary for it to pass
        std::map<int, int> mp;
        int maxFreq = std::numeric_limits<int>::min();
        for (int j = 0; j < N; ++j) {
            int x;
            std::cin >> x;
            mp[x]++;
            // caching frequency in variable is necessary to pass
            int freq = mp[x];
            if(maxFreq < freq) {
                maxFreq = freq;
            }
        }
        int res = 0;
        int remaining = N - maxFreq;
        if(maxFreq > remaining) {
            res = (maxFreq - remaining);
        }
        else {
            res = (remaining - maxFreq) % 2;
        }
        std::cout << res << "\n"; 
    }
    return 0;
}