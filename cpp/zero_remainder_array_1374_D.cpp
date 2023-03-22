#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <algorithm>

using lli = long long int;

auto findMinMovesToConvertToZeroRemainderArray(std::map<int, int>& diffFreq, int K) -> lli {

    lli x = 0;
    for(const auto& currentDiff: diffFreq) {
        if(currentDiff.second > 1) {
            lli potentialValue = static_cast<lli>(currentDiff.first) + 1 + ((static_cast<lli>(currentDiff.second - 1)) * static_cast<lli>(K));
            x = std::max(x, potentialValue);
        }
        else if(x <= currentDiff.first){
            x = currentDiff.first + 1;
        }
    }
    return x;
}

auto main() -> int {
    int T;
    std::cin >> T;

    std::stringstream result{""};

    for (int i = 0; i < T; ++i) {
        int N, K;
        std::cin >> N >> K;

        std::map<int, int> diffFreq;
        for (int j = 0; j < N; ++j) {
            int x;
            std::cin >> x;
            int diff = K - (x % K);
            if(diff > 0 && diff < K) {
                diffFreq[diff]++;
            }
        }

        result << (findMinMovesToConvertToZeroRemainderArray(diffFreq, K)) << "\n"; 
    }

    std::cout << result.str() << std::endl;
    
    return 0;
}