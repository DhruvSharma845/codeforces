#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <string>

auto solveQueriesIfStoragesCanBeBuilt(std::map<int, int>& lenToFreq) -> std::string {
    int numOfFreqFour = 0;
    int numOfFreqTwo = 0;
    for(const auto& pr: lenToFreq) {
        numOfFreqFour += (pr.second/4);
        numOfFreqTwo += (pr.second/2);
    }

    int Q;
    std::cin >> Q;

    std::stringstream ss{""};
    for(int i = 0; i < Q; ++i) {
        char c;
        int len;
        std::cin >> c >> len;
        if(c == '+') {
            numOfFreqFour -= (lenToFreq[len]/4);
            numOfFreqTwo -= (lenToFreq[len]/2);
            lenToFreq[len]++;
            numOfFreqFour += (lenToFreq[len]/4);
            numOfFreqTwo += (lenToFreq[len]/2);
        }
        else if(c == '-') {
            numOfFreqFour -= (lenToFreq[len]/4);
            numOfFreqTwo -= (lenToFreq[len]/2);
            lenToFreq[len]--;
            numOfFreqFour += (lenToFreq[len]/4);
            numOfFreqTwo += (lenToFreq[len]/2);
        }
        
        bool isPossible = true;
        if(numOfFreqFour < 1) {
            isPossible = false;
        }
        int clonedTwos = numOfFreqTwo - 2;
        if(clonedTwos < 2) {
            isPossible = false;
        }
        if(isPossible) {
            ss << "YES\n";
        }
        else {
            ss << "NO\n";
        }
    }
    return ss.str();
}

auto main() -> int {
    int N;
    std::cin >> N;

    std::map<int, int> lenToFreq;
    for (int i = 0; i < N; ++i) {
        int l;
        std::cin >> l;
        lenToFreq[l]++;
    }
    std::cout << solveQueriesIfStoragesCanBeBuilt(lenToFreq);
}