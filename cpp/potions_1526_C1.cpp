#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using lli = long long int;

auto main() -> int {
    int N;
    std::cin >> N;

    lli currentSum = 0L;
    int count = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (auto i = 0; i < N; ++i) {
        int pValue;
        std::cin >> pValue;

        currentSum += pValue;
        ++count;

        if(pValue < 0) {
            pq.push(pValue);
        }

        if(currentSum < 0) {
            int minValue = pq.top();
            pq.pop();
            --count;
            currentSum -= minValue;
        }
    }
    std::cout << count << std::endl;
}


/*

*/