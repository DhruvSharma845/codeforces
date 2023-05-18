#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>
#include <set>

using RelationshipList = std::unordered_map<int, std::vector<int>>;

auto doDFS(
    const RelationshipList& elementGroups, 
    const RelationshipList& groupsContainment, 
    std::vector<bool>& visited, 
    int cc, 
    std::vector<int>& elementCC, 
    std::unordered_map<int, int>& ccFreq,
    int elem,
    std::set<int>& currentGroupsInStack) -> void {

        visited[elem] = true;
        elementCC[elem] = cc;
        ccFreq[cc]++;

        if(elementGroups.find(elem) != elementGroups.end()) {
            for(const int& group: elementGroups.at(elem)) {
                if(currentGroupsInStack.find(group) == currentGroupsInStack.end() && groupsContainment.find(group) != groupsContainment.end()) {
                    currentGroupsInStack.insert(group);
                    for(const int& neighbor: groupsContainment.at(group)) {
                        if(visited[neighbor] == false) {
                            doDFS(elementGroups, groupsContainment, visited, cc, elementCC, ccFreq, neighbor, currentGroupsInStack);
                        }
                    }
                    currentGroupsInStack.erase(group);
                }
            }
        }
}

auto traverseGraphAndFindConnectedComponents(const RelationshipList& elementGroups, const RelationshipList& groupsContainment, int N) -> std::string {
    std::vector<bool> visited(N + 1, false);
    std::vector<int> elementCC(N + 1, -1);
    std::unordered_map<int, int> ccFreq;

    std::set<int> currentGroupsInStack;

    int cc = 0;
    for(int i = 1; i <= N; ++i) {
        if(visited[i] == false) {
            ++cc;
            doDFS(elementGroups, groupsContainment, visited, cc, elementCC, ccFreq, i, currentGroupsInStack);
        }
    }

    std::stringstream ss{""};
    for (int i = 1; i <= N; ++i) {
        int cc = elementCC[i];
        ss << ccFreq[cc] << " ";
    }
    return ss.str();
    
}

auto main() -> int {
    int N, M;
    std::cin >> N >> M;

    RelationshipList groupsContainment;
    RelationshipList elementGroups;
    for (int i = 0; i < M; ++i) {
        int K;
        std::cin >> K;
        groupsContainment[i+1].reserve(K);
        for (int j = 0; j < K; ++j) {
            int elem;
            std::cin >> elem;
            elementGroups[elem].push_back(i+1);
            groupsContainment[i+1].push_back(elem);
        }
    }

    std::string res = traverseGraphAndFindConnectedComponents(elementGroups, groupsContainment, N);
    std::cout << res << std::endl;
    return 0;
}