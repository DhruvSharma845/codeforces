#include <iostream>
#include <vector>
#include <unordered_set>

auto main() -> int {
    int N, M;
    std::cin >> N >> M;

    std::unordered_set<int> bannedVertices;
    for (int i = 0; i < M; i++) {
        int f,s;
        std::cin >> f >> s;
        bannedVertices.insert(f);
        bannedVertices.insert(s);
    }
    int root = -1;
    for(int i = 1; i <= N; i++) {
        if(bannedVertices.find(i) == bannedVertices.end()) {
            root = i;
            break;
        }
    }

    std::cout << (N-1) << std::endl;
    for (int i = 1; i <= N; i++) {
        if(i != root) {
            std::cout << root << " " << i << std::endl;
        }
    }
}