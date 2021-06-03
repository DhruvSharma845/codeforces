#include <iostream>
#include <vector>
#include <string>
#include <limits>

const int MAXINT = std::numeric_limits<int>::max();
const int MININT = std::numeric_limits<int>::min();

auto isSortPossibleWithSwaps(std::vector<int>& v, const std::string& swaps) -> bool {
    
    auto minNum = int{MAXINT};
    auto maxNum = int{MININT};
    int left = -1;
    size_t i = 0;
    for (; i < swaps.length(); i++) {
        if(swaps[i] == '0') {
            if(left != -1) {
                if(v[i] < minNum) {
                    minNum = v[i];
                }
                if(v[i] > maxNum) {
                    maxNum = v[i];
                }
                if(maxNum != (i+1) || minNum != (left+1)) {
                    return false;
                }
                left = -1;
            }
            else {
                if(v[i] != (i+1)) {
                    return false;
                }
            }
            minNum = MAXINT;
            maxNum = MININT;
        }
        else {
            if(left == -1) {
                left = i;
            }
            if(v[i] < minNum) {
                minNum = v[i];
            }
            if(v[i] > maxNum) {
                maxNum = v[i];
            }
        }
    }
    if(left != -1) {
        if(v[i] < minNum) {
            minNum = v[i];
        }
        if(v[i] > maxNum) {
            maxNum = v[i];
        }
        if(maxNum != (i+1) || minNum != (left+1)) {
            return false;
        }
    }
    return true;
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> v(n, 0);
    for (size_t i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    std::string swapPossible;
    std::cin >> swapPossible;

    if(isSortPossibleWithSwaps(v, swapPossible) == true) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
}

/*
3 2 1
0 0 0
*/