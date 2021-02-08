#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> damage(N, 0);
    for (size_t i = 0; i < N; ++i) {
        std::cin >> damage[i];
    }
    
    std::string hits;
    std::cin >> hits;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int counter = 0;
    long long int sum = 0;
    for(int i = 0; i < hits.size(); ++i) {
        if(i == 0 || hits.at(i) != hits.at(i-1)) {
            while(!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
            pq = std::priority_queue<int, std::vector<int>, std::greater<int>>();
            counter = 0;
        }
        if(counter < K) {
            pq.push(damage[i]);
            ++counter;
        }
        else {
            if(damage[i] > pq.top()) {
                pq.pop();
                pq.push(damage[i]);
            }
        }
    }
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    std::cout << sum << std::endl;
}