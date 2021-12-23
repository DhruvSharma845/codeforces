#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

auto main() -> int {
    int N;
    std::cin >> N;

    std::vector<int> seq(N, 0);
    for(int i = 0; i < N; ++i) {
        std::cin >> seq[i];
    }

    std::vector<int> sortedSeq(seq.begin(), seq.end());
    std::sort(sortedSeq.begin(), sortedSeq.end());

    std::unordered_map<int, int> indices;
    for(int i = 0; i < sortedSeq.size(); ++i) {
        indices[sortedSeq[i]] = i;
    }

    std::vector<bool> visited(N, false);

    std::vector<std::vector<int>> subsequences;
    for(int i = 0; i < seq.size(); ++i) {
        if(visited[i] == false) {
            std::vector<int> subsequence;
            subsequence.push_back(i + 1);
            visited[i] = true;
            
            int startIndex = i;
            int element = seq[i];
            int gotoIndex = indices[element];
            
            while(gotoIndex != startIndex) {
                subsequence.push_back(gotoIndex + 1);
                visited[gotoIndex] = true;
                element = seq[gotoIndex];
                gotoIndex = indices[element];
            }
            subsequences.push_back(subsequence);
        }
    }

    std::cout << subsequences.size() << std::endl;
    for(auto& subsequence: subsequences) {
        std::cout << subsequence.size() << " ";
        for(int index: subsequence) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }
}


/*
33 22 11 66 55 44


11 22 33 44 55 66
*/