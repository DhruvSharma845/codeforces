#include <iostream>
#include <map>
#include <set>
#include <sstream>

auto main() -> int {
    int N, M;
    std::cin >> N >> M;

    std::map<int, std::set<int>> friendshipAdjList;
    for (int i = 0; i < M; ++i) {
        int u, v;
        std::cin >> u >> v;
        friendshipAdjList[u].insert(v);
        friendshipAdjList[v].insert(u);
    }

    std::set<int> retained;
    for (int i = 1; i <= N; ++i) {
        retained.insert(retained.end(), i);
    }
    for(const auto& pr: friendshipAdjList) {
        if(pr.second.size() > 0) {
            auto it = pr.second.lower_bound(pr.first);
            if(it == pr.second.end()) {
                retained.insert(pr.first);
            }
            else {
                retained.erase(pr.first);
            }
        }
    }

    int q;
    std::cin >> q;

    std::stringstream ss{""};
    for(int i = 0; i < q; ++i) {
        int qNum;
        std::cin >> qNum;
        switch (qNum)
        {
        case 1:
            int u, v;
            std::cin >> u >> v;
            friendshipAdjList[u].insert(v);
            if(friendshipAdjList[u].size() > 0) {
                auto it = friendshipAdjList[u].lower_bound(u);
                if(it == friendshipAdjList[u].end()) {
                    retained.insert(u);
                }
                else {
                    retained.erase(u);
                }
            }
            friendshipAdjList[v].insert(u);
            if(friendshipAdjList[v].size() > 0) {
                auto it = friendshipAdjList[v].lower_bound(v);
                if(it == friendshipAdjList[v].end()) {
                    retained.insert(v);
                }
                else {
                    retained.erase(v);
                }
            }
            break;
        case 2:
            int u1, v1;
            std::cin >> u1 >> v1;
            friendshipAdjList[u1].erase(v1);
            if(friendshipAdjList[u1].size() > 0) {
                auto it = friendshipAdjList[u1].lower_bound(u1);
                if(it == friendshipAdjList[u1].end()) {
                    retained.insert(u1);
                }
                else {
                    retained.erase(u1);
                }
            }
            else {
                retained.insert(u1);
            } 
            friendshipAdjList[v1].erase(u1);
            if(friendshipAdjList[v1].size() > 0) {
                auto it = friendshipAdjList[v1].lower_bound(v1);
                if(it == friendshipAdjList[v1].end()) {
                    retained.insert(v1);
                }
                else {
                    retained.erase(v1);
                }
            }
            else {
                retained.insert(v1);
            }
            break;
        case 3:
            ss << retained.size() << "\n";
            break;
        }
    }
    std::cout << ss.str();
    return 0;
}