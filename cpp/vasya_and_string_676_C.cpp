#include <iostream>
#include <string>

auto areAllElementsMoreThanK(int* freq, int numOfChars, int K) -> bool {
    for (int i = 0; i < numOfChars; ++i) {
        if(freq[i] <= K) {
            return false;
        }
    }
    return true;
}

auto findMaximumPossibleBeauty(const std::string& str, int K) -> int {

    int maxBeauty = 0;
    int start = 0;
    int end = 0;
    int freq[2] = {0, 0};
    while(end < str.size()) {
        freq[str[end] - 'a']++;
        while(areAllElementsMoreThanK(freq, 2, K)) {
            freq[str[start] - 'a']--;
            ++start;
        }
        ++end;
        if(end - start > maxBeauty) {
            maxBeauty = end - start;
        }
    }
    if(end - start > maxBeauty) {
        maxBeauty = end - start;
    }
    return maxBeauty;
}

auto main() -> int {
    int N, K;
    std::cin >> N >> K;

    std::string str{""};
    std::cin >> str;

    std::cout << findMaximumPossibleBeauty(str, K) << std::endl;
    return 0;
}