#include <iostream>
#include <unordered_map>
#include <vector>

auto doDFS(std::unordered_map<int, std::vector<int>>& graph, int currentVertex, std::vector<bool>& visited, bool& hasVertexWithNotEqual2Edges) -> void {
    visited[currentVertex] = true;
    if(graph[currentVertex].size() != 2) {
        hasVertexWithNotEqual2Edges = true;
    }
    for(auto neighbor: graph[currentVertex]) {
        if(visited[neighbor] == false) {
            doDFS(graph, neighbor, visited, hasVertexWithNotEqual2Edges);
        }
    }
}

auto calculateCyclicConnectedComponents(std::unordered_map<int, std::vector<int>>& graph, int V, int E) -> int {
    std::vector<bool> visited(V + 1, false);

    int cyclicConnectedComponents{0};
    for(int i = 1; i <= V; ++i) {
        if(visited[i] == false) {
            bool hasVertexWithNotEqual2Edges = false;
            doDFS(graph, i, visited, hasVertexWithNotEqual2Edges);
            if(hasVertexWithNotEqual2Edges == false) {
                ++cyclicConnectedComponents;
            }
        }
    }
    return cyclicConnectedComponents;
}

auto main() -> int {
    int V, E;
    std::cin >> V >> E;

    std::unordered_map<int, std::vector<int>> graph;
    for(auto i = 0; i < E; ++i) {
        int e1, e2;
        std::cin >> e1 >> e2;

        graph[e1].push_back(e2);
        graph[e2].push_back(e1);
    }

    std::cout << calculateCyclicConnectedComponents(graph, V, E) << std::endl;
    return 0;
}