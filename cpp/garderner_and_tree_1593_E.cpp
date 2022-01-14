#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>

auto main() -> int {

    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        int N, K;
        std::cin >> N >> K;

        std::vector<int> neighborCount(N, 0);
        std::unordered_map<int, std::set<int>> tree;
        for (int j = 0; j < N - 1; ++j) {
            int u, v;
            std::cin >> u >> v;
            ++(neighborCount[u-1]);
            ++(neighborCount[v-1]);
            tree[u-1].insert(v-1);
            tree[v-1].insert(u-1); 
        }

        std::queue<int> que;
        int index = 0;
        for(auto elem: neighborCount) {
            if(elem == 0 || elem == 1) {
                que.push(index);
            }
            ++index;
        }

        while(!que.empty() && K > 0) {
            int queSize = que.size();
            while(queSize > 0) {
                int node = que.front();
                que.pop();
                //std::cout << "Removed node: " << node << std::endl;
                neighborCount[node] = -1;
                if(tree.find(node) != tree.end()) {
                    for(const auto& neighbor: tree[node]) {
                        --(neighborCount[neighbor]);
                        if(neighborCount[neighbor] == 0 || neighborCount[neighbor] == 1) {
                            que.push(neighbor);
                        }
                        tree[neighbor].erase(node);
                    }
                }
                tree.erase(node);
                --queSize;
            }
            --K;
        }

        std::cout << std::count_if(neighborCount.begin(), neighborCount.end(), [](const int& val) { return val >= 0; }) << std::endl;
    }
    
}