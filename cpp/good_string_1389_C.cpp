#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

auto minimumCharactersToErase(const std::string& str) -> int {
    std::unordered_map<int, std::vector<int>> numIndices;
    for(int i = 0; i < str.length(); ++i) {
        numIndices[str[i] - '0'].push_back(i);
    }

    int minChars = str.length();
    for(const auto& entry: numIndices) {
        int firstNum = entry.first;
        const std::vector<int>& firstNumIndices = entry.second;
        if((str.length() - firstNumIndices.size()) < minChars) {
            minChars = str.length() - firstNumIndices.size();
        }
        for(const auto& secondEntry: numIndices) {
            int secondNum = secondEntry.first;
            const std::vector<int>& secondNumIndices = secondEntry.second;
            if(secondNumIndices[0] > firstNumIndices[0]) {
                int validLength = 0;

                int f = 0;
                int s = 0;
                while(f < firstNumIndices.size() && s < secondNumIndices.size()) {
                    bool foundFirst = false;
                    bool foundSecond = false;
                    while(f < firstNumIndices.size() && firstNumIndices[f] < secondNumIndices[s]) { 
                        foundFirst = true;
                        ++f;
                    }
                    while(s < secondNumIndices.size() && (f >= firstNumIndices.size() || secondNumIndices[s] < firstNumIndices[f])) {
                        foundSecond = true;
                        ++s;
                    }
                    if(foundFirst && foundSecond) {
                        validLength += 2;
                    }
                }
                if(str.length() - validLength < minChars) {
                    minChars = str.length() - validLength;
                }
            }
        }
    }
    
    return minChars;
}

auto main() -> int {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        std::string s;
        std::cin >> s;

        std::cout << minimumCharactersToErase(s) << std::endl;
    }
    
    return 0;
}