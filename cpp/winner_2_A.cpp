#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>

auto main() -> int {
    int N;
    std::cin >> N;

    std::unordered_map<std::string, std::vector<std::pair<int, int>>> scoresMap;
    std::map<int, std::unordered_set<std::string>> reverseScoreMap;

    for(int i = 0; i < N; ++i) {
        std::string name;
        int score;
        std::cin >> name >> score;
        if(scoresMap.find(name) == scoresMap.end()) {
            scoresMap[name].push_back(std::pair<int, int>(score, i));
            reverseScoreMap[score].insert(name);
        }
        else {
            auto oldScore = scoresMap[name].back().first;
            auto newScore = oldScore + score;
            scoresMap[name].push_back(std::pair<int, int>(newScore, i));
            reverseScoreMap[oldScore].erase(name);
            reverseScoreMap[newScore].insert(name);
        }
    }

    auto lastEntryReverseMap = reverseScoreMap.rbegin();
    while(lastEntryReverseMap != reverseScoreMap.rend()) {
        if((*lastEntryReverseMap).second.size() > 0) {
            break;
        }
        ++lastEntryReverseMap;
     }

    int index = std::numeric_limits<int>::max();
    std::string nameWithMaxScoreAndLowestIndex("");
    for(const auto& name: (*lastEntryReverseMap).second) {
        for(const auto& scoreWithIndex: scoresMap[name]) {
            if(scoreWithIndex.first >= (*lastEntryReverseMap).first && scoreWithIndex.second < index) {
                index = scoreWithIndex.second;
                nameWithMaxScoreAndLowestIndex = name;
            }
        }
    }
    
    std::cout << nameWithMaxScoreAndLowestIndex << std::endl;
    return 0;
}