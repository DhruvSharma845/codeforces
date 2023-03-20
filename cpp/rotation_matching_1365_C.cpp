/*
* 1 2 3 4 5
* 2 3 4 5 1
*
* 4 0 1 2 3
*/


/*
* 5 4 3 2 1
* 1 2 3 4 5
*
* 4 3 2 1 0
*/


/*
* 1 3 2 4
* 4 2 3 1
*
* 3 2 1 0
*/

#include <iostream>
#include <vector>
#include <unordered_map>

auto main() -> int {
    int N;
    std::cin >> N;

    std::vector<int> indexTable(N + 1, -1);
    std::unordered_map<int, int> distanceTable;
    for (int i = 0; i < N; ++i) {
        int a;
        std::cin >> a;
        indexTable[a] = i;
    }

    for (int i = 0; i < N; ++i) {
        int b;
        std::cin >> b;
        int indexInA = indexTable[b];

        distanceTable[(i - indexInA + N) % N]++;
    }
    
    int maxPairs = 0;
    for (const auto &pr : distanceTable) {
        if(pr.second > maxPairs) {
            maxPairs = pr.second;
        }
    }
    
    std::cout << maxPairs << std::endl;
    
    return 0;
}