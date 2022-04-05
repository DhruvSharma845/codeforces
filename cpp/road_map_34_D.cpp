#include <iostream>
#include <vector>

auto main() -> int {
    int N, R1, R2;
    std::cin >> N >> R1 >> R2;

    std::vector<int> parents(N + 1, -1);
    for (int i = 1; i < R1; ++i) {
        int p; 
        std::cin >> p;
        parents[i] = p;
    }
    for(int i = R1 + 1; i <= N; ++i) {
        int p;
        std::cin >> p;
        parents[i] = p;
    }

    int current = R2;
    int parent = parents[R2];
    parents[R2] = -1;
    int parentParent = parents[parent];
    while(parent != -1) {
        parents[parent] = current;
        current = parent;
        parent = parentParent;
        if(parent != -1) {
            parentParent = parents[parent];
        } 
    }


    for (int i = 1; i < R2; ++i) {
        std::cout << parents[i] << " ";
    }
    for(int i = R2 + 1; i <= N; ++i) {
        std::cout << parents[i] << " ";
    }
    std::cout << std::endl;
}