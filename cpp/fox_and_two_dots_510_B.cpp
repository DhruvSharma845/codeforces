#include <iostream>
#include <string>
#include <vector>
#include <utility>

auto isCyclic(const std::vector<std::string>& puzzle, std::vector<std::vector<bool>>& visited, int curRow, int curCol, std::pair<int, int> parent) -> bool {
    int n = puzzle.size();
    int m = puzzle[0].length();

    visited[curRow][curCol] = true;
    auto color = puzzle[curRow][curCol];

    //std::cout << "Parent: " << parent.first << ":" << parent.second << std::endl;
    //std::cout << "Current: " << curRow << ":" << curCol << std::endl;

    std::vector<int> rowInc{0, -1, 0, 1};
    std::vector<int> colInc{1, 0, -1, 0};
    for (size_t i = 0; i < rowInc.size(); i++) {
        auto nextRow = curRow + rowInc[i];
        auto nextCol = curCol + colInc[i];
        if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && puzzle[nextRow][nextCol] == color) {
            //std::cout << "Next: " << nextRow << ":" << nextCol << std::endl;
            if(visited[nextRow][nextCol] == false) {
                if(isCyclic(puzzle, visited, nextRow, nextCol, std::make_pair(curRow, curCol)) == true) {
                    return true;
                }
            }
            else if(nextRow != parent.first && nextCol != parent.second) {
                return true;
            }
        }
    }
    return false;
}

auto main() -> int {
    auto n = int{0};
    auto m = int{0};
    std::cin >> n >> m;

    std::vector<std::string> puzzle(n, std::string{""});
    for (int i = 0; i < n; i++) {
        std::cin >> puzzle[i]; 
    }
    
    auto hasCycle = bool{false};
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(visited[i][j] == false && isCyclic(puzzle, visited, i, j, std::make_pair<int, int>(-1, -1)) == true) {
                //std::cout << "Cycle found: " << i << ":" << j << std::endl;
                hasCycle = true;
                break;
            }
        }
    }
    if(hasCycle == true) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
}