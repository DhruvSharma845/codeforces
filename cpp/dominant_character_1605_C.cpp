#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>

auto findSmallestSubstringWithConditions(const std::string& str) -> int {
    int minLength = std::numeric_limits<int>::max();
    for(int i = 1; i < str.size(); ++i) {
        int countA = 0; 
        int countB = 0;
        int countC = 0;

        for(int j = 0; j < 7 && (i-j) >= 0; ++j) {
            switch(str[i-j]) {
                case 'a':
                ++countA;
                break;
                case 'b':
                ++countB;
                break;
                case 'c':
                ++countC;
                break;
            }
            if((countA + countB + countC) >= 2 && countA > countB && countA > countC) {
                minLength = std::min(minLength, (countA + countB + countC));
            }
        }
    }
    return (minLength == std::numeric_limits<int>::max()) ? -1 : minLength;
}

auto main() -> int {
    int T;
    std::cin >> T;

    std::stringstream ss{""};
    for (int i = 0; i < T; ++i) {
        int N;
        std::cin >> N;
        std::string s;
        std::cin >> s;

        ss << findSmallestSubstringWithConditions(s) << std::endl;
    }

    std::cout << ss.str();
    
    return 0;
}