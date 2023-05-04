#include <iostream>
#include <map>
#include <algorithm>
#include <limits>
#include <cstdint>

auto findMinimumMoves(const std::map<int, int>& freqMap, int minE, int maxE, int D, int N, int M) -> uint32_t {
    if(minE == maxE) {
        return 0;
    }
    int totalElems = N * M;
    
    // find left and right moves to move to minE
    int leftMoves = 0;
    int rightMoves = 0;
    for(const auto& [elem, freq]: freqMap) {
        if(elem > minE) {
            rightMoves += (((elem - minE) / D) * freq);
        }
    }

    int minMovesSoFar = leftMoves + rightMoves;
    int leftSideElems = freqMap.at(minE);
    int rightSideElems = totalElems - leftSideElems;
    for(int i = minE + D; i <= maxE; i += D) {
        if(freqMap.find(i) == freqMap.end()) {
            leftMoves += leftSideElems;
            rightMoves -= rightSideElems;
        }
        else {
            leftMoves += leftSideElems;

            auto freq = freqMap.at(i);
            rightMoves -= rightSideElems;
            leftSideElems += freq;
            rightSideElems -= freq;
        }
        
        int currentMoves = leftMoves + rightMoves;
        minMovesSoFar = std::min(currentMoves, minMovesSoFar);
    }
    
    return minMovesSoFar;
}

auto main() -> int {
    int N, M, D;
    std::cin >> N >> M >> D;

    std::map<int, int> freqMap;

    int minE = std::numeric_limits<int>::max();
    int maxE = std::numeric_limits<int>::min();

    int remainder = -1;
    for(int i = 0; i < N * M; ++i) {
        int x;
        std::cin >> x;
        if(remainder == -1) {
            remainder = x % D;
        }
        else if(remainder != (x % D)){
            std::cout << "-1" << std::endl;
            return 0;
        }
        freqMap[x]++;
        minE = std::min(minE, x);
        maxE = std::max(maxE, x);
    }

    std::cout << findMinimumMoves(freqMap, minE, maxE, D, N , M) << std::endl;

    return 0;
}