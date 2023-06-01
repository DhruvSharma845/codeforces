#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>
#include <set>

auto isConvertible(const std::string& from, const std::string& to, int K) -> bool {
    std::map<char, int> charFreqMap;
    for (const auto& ch : from) {
        charFreqMap[ch]++;
    }

    std::map<char, int> charFreqMapTo;
    for(const auto& ch: to) {
        charFreqMapTo[ch]++;
    }

    for(const auto& pr: charFreqMapTo) {
        int freqInTo = pr.second;
        if(charFreqMap.find(pr.first) != charFreqMap.end()) {
            int freqInFrom = charFreqMap[pr.first];
            if(freqInFrom >= freqInTo) {
                charFreqMap[pr.first] = (freqInFrom - freqInTo);
                freqInTo = 0;
            }
            else {
                freqInTo = (freqInTo - freqInFrom);
                charFreqMap[pr.first] = 0;
            }
        }
        if(freqInTo % K != 0) {
            return false;
        }
        if(freqInTo > 0) {
            for(const auto& fromPr: charFreqMap) {
                if(fromPr.first >= pr.first) {
                    break;
                }
                if(fromPr.second >= K) {
                    int count = std::min((fromPr.second / K), (freqInTo / K)) * K;
                    freqInTo -= count;
                    charFreqMap[fromPr.first] -= count;
                }
                if(freqInTo % K != 0) {
                    return false;
                }
                if(freqInTo == 0) {
                    break;
                }
            }
        }
        if(freqInTo > 0) {
            return false;
        }
    }
    return true;
}

auto main() -> int {
    int T;
    std::cin >> T;

    std::stringstream ss{""};
    for (int i = 0; i < T; ++i) {
        int N, K;
        std::cin >> N >> K;

        std::string from;
        std::string to;
        std::cin >> from;
        std::cin >> to;

        if(isConvertible(from, to, K) == true) {
            ss << "Yes\n";
        }
        else {
            ss << "No\n";
        }
    }
    std::cout << ss.str();
    return 0;
}
