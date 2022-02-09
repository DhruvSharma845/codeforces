#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

auto main() -> int {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> studentFeatures; /* {
        {30, 17},
        {41, 32},
        {12, 4},
        {7, 1},
        {5,5},
        {29, 30},
        {5, 10},
        {3, 15},
        {31, 45},
        {20, 55},
    };*/
    studentFeatures.reserve(N);
    for (int i = 0; i < N; ++i) {
        int A, B;
        std::cin >> A >> B;
        studentFeatures.emplace_back(A, B);
    }
    std::sort(studentFeatures.begin(), studentFeatures.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first - a.second) > (b.first - b.second);
    });
        long long int totalDissatisfaction = 0l;
        long long int i = 0;
        for(const auto& p: studentFeatures) {
            //std::cout << p.first << " " << p.second << ":" << totalDissatisfaction << std::endl;
            totalDissatisfaction += (p.first * i + p.second * (N - i - 1));
            ++i;
        }
        std::cout << totalDissatisfaction << std::endl;
}