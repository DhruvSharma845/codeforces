#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using MapWithSetValue = std::unordered_map<int, std::unordered_set<int>>;

auto doDFS(int person, const MapWithSetValue& personToLang, const MapWithSetValue& langToPerson, std::vector<bool>& visited) -> void {
    visited[person] = true;

    if(personToLang.find(person) != personToLang.end()) {
        for(const auto& knownLang: personToLang.at(person)) {
            if(langToPerson.find(knownLang) != langToPerson.end()) {
                for(const auto& neighbor: langToPerson.at(knownLang)) {
                    if(visited[neighbor] == false) {
                        doDFS(neighbor, personToLang, langToPerson, visited);
                    }
                }
            }
        }
    }
}

auto findMinimumAmountToPay(const MapWithSetValue& personToLang, const MapWithSetValue& langToPerson, int numPersons, int numLangs) -> int {
    std::vector<bool> visited(numPersons, false);

    int countOfDistinctGraphs= 0;
    for(int i = 0; i < numPersons; ++i) {
        if(visited[i] == false) {
            ++countOfDistinctGraphs;
            doDFS(i, personToLang, langToPerson, visited);
        }
    }
    return personToLang.size() == 0 ? countOfDistinctGraphs: (countOfDistinctGraphs - 1);
}

auto main() -> int {
    int N, M;
    std::cin >> N >> M;

    MapWithSetValue personToLang;
    MapWithSetValue langToPerson;
    for(int i = 0; i < N; ++i) {
        int K;
        std::cin >> K;
        for(int j = 0; j < K; ++j) {
            int x;
            std::cin >> x;
            personToLang[i].insert(x);
            langToPerson[x].insert(i); 
        }
    }

    std::cout << findMinimumAmountToPay(personToLang, langToPerson, N, M) << std::endl;
    return 0;
}