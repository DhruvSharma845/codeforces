#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n;
    std::cin>>n;

    std::vector<std::vector<int>> mat(100, std::vector<int>(100, 0));

    for (size_t i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin>>x1>>y1>>x2>>y2;

        for(size_t x = x1 - 1; x <= x2 - 1; ++x) {
            for(size_t y = y1 - 1; y <= y2 - 1; ++y) {
                mat[y][x] += 1;
            }
        }
    }

    int sum = 0;

    for (size_t i = 0; i < 100; i++)
    {
        //std::copy(mat[i].begin(), mat[i].end(), std::ostream_iterator<int>(std::cout, " "));
        sum += std::accumulate(mat[i].begin(), mat[i].end(), 0);
        //std::cout << std::endl;
    }
    
    std::cout << sum << std::endl;
}