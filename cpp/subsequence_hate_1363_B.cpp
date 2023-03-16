#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

auto findMinOperationsToMakeGood(const std::string& s) -> int {
    int numOfZeroes = std::count(s.begin(), s.end(), '0');
    int numOfOnes = s.size() - numOfZeroes;

    int minOperations = std::numeric_limits<int>::max();
    int currentCountOfZeroes = 0;
    int currentCountOfOnes = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '1') {
            ++currentCountOfOnes;
        }
        else {
            ++currentCountOfZeroes;
        }
        // current index is end point of one
        int leftSideOnes = currentCountOfZeroes + (numOfOnes - currentCountOfOnes);
        // current index is end point of zero
        int leftSizeZeroes = currentCountOfOnes + (numOfZeroes - currentCountOfZeroes);

        minOperations = std::min(minOperations, std::min(leftSideOnes, leftSizeZeroes));
    }
    return minOperations;
}

auto main() -> int {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        using namespace std::string_literals;
        std::string s{""s};

        std::cin >> s;

        std::cout << findMinOperationsToMakeGood(s) << std::endl;
    }
    
    return 0;
}