#include <iostream>
#include <queue>
#include <utility>
#include <set>

int findMinimumClick(int src, int tgt) {
    if(tgt < src) {
        return (src - tgt);
    }

    std::queue<std::pair<int, int>> q;
    std::set<int> visited;

    q.push(std::make_pair(src, 0));
    while(!q.empty()) {
        auto pr = q.front();
        q.pop();

        if(pr.first == tgt) {
            return pr.second;
        }

        if(pr.first * 2 == tgt || pr.first - 1 == tgt) {
            return (pr.second + 1);
        }

        visited.insert(pr.first);

        if((pr.first * 2 <= tgt * 2) && visited.find(pr.first * 2) == visited.end()) {
            q.push(std::make_pair(pr.first * 2, pr.second + 1));
        }
        if((pr.first - 1) >= 0 && visited.find(pr.first - 1) == visited.end()) {
            q.push(std::make_pair(pr.first - 1, pr.second + 1));
        }
    }
    return -1;
}

auto main() -> int {
    int n, m;
    std::cin >> n >> m;

    std::cout << findMinimumClick(n, m) << std::endl;
    return 0;
}