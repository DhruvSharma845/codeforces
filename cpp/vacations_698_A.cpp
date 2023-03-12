#include <iostream>
#include <vector>

auto findMinimumRestDays(const std::vector<int>& tasks) -> int {
    std::vector<std::vector<int>> dpTable(3, std::vector<int>(tasks.size() + 1, 0));

    for(int i = 1; i <= tasks.size(); ++i) {
        // rest
        dpTable[0][i] = std::min(std::min(dpTable[0][i-1], dpTable[1][i-1]), dpTable[2][i-1]) + 1;
        // contest
        dpTable[1][i] = (tasks[i-1] == 1 || tasks[i-1] == 3) ? std::min(dpTable[0][i-1], dpTable[2][i-1]): std::min(std::min(dpTable[0][i-1], dpTable[1][i-1]), dpTable[2][i-1]) + 1;
        // sport 
        dpTable[2][i] = (tasks[i-1] == 2 || tasks[i-1] == 3) ? std::min(dpTable[0][i-1], dpTable[1][i-1]): std::min(std::min(dpTable[0][i-1], dpTable[1][i-1]), dpTable[2][i-1]) + 1; 
    }

    return std::min(std::min(dpTable[0][tasks.size()], dpTable[1][tasks.size()]), dpTable[2][tasks.size()]);
}

auto main() -> int {
    int numOfVacations;
    std::cin >> numOfVacations;

    std::vector<int> tasks;
    tasks.reserve(numOfVacations);
    for(int i = 0; i < numOfVacations; ++i) {
        int task;
        std::cin >> task;
        tasks.push_back(task);
    }
    std::cout << findMinimumRestDays(tasks) << std::endl;
    return 0;
}