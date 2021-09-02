#include <iostream>
#include <unordered_map>
#include <vector>

auto dfs(int& evensCount, int vertex, const std::unordered_map<int, std::vector<int>>& graph, std::vector<bool>& visited,
    std::unordered_map<int, int>& parent) -> int {
    visited[vertex] = true;
    int cnt= 1;

    if(graph.find(vertex) != graph.end()) {
        for (const auto& neighbor: graph.at(vertex)) {
            
            if(parent.find(vertex) != parent.end() && neighbor == parent[vertex]) {
                continue;
            }

            if(visited[neighbor] == false){
                parent[neighbor] = vertex;
                cnt += dfs(evensCount, neighbor, graph, visited, parent);
            }
        }
    }

    if(cnt %2 == 0)  evensCount++; 
    return cnt;
}

auto main() -> int {
    int n;
    std::cin >> n;

    std::unordered_map<int, std::vector<int>> graph;
    
    for (int i = 0; i < n - 1; i++) {
        int start, end;
        std::cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    if(n % 2 == 1) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    std::vector<bool> visited(n + 1, false);
    std::unordered_map<int, int> parent;
    int evens = 0;
    for (int i = 0; i < n; i++) {
        if(visited[i] == false) {
            dfs(evens, i, graph, visited, parent);
        }
    }
    
    std::cout << (evens - 1) << std::endl;
    
}