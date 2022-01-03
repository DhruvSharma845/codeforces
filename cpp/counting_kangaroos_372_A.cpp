#include <iostream>
#include <vector>
#include <algorithm>

auto calculateHoldings(const std::vector<int>& sizes, int startingPoint) -> int {
    int big = startingPoint;
    int small = big;
    int half = sizes[big] / 2;
    while(small >= 0 && sizes[small] > half) {
        --small;
    }
    //std::cout << big << ":" << small << std::endl; 
    
    int result = 0;
    if(small < 0) {
        return (sizes.size() - result);
    }
    ++result;
    --big;
    int current = small - 1;
    while(big >= 0) {
        while(current >= 0 && sizes[current] > (sizes[big]/2)) {
            --current;
        }
        if(current >= 0 && sizes[current] <= (sizes[big]/2)) {
            //std::cout << big << ":" << current << std::endl;
            ++result;
            --current;
        }
        else if(current < 0) {
            break;
        }
        --big;
    }
    if (sizes.size() % 2 == 1) {
        if (result > sizes.size() / 2)
            return (sizes.size() / 2 + 1);
        else
            return (sizes.size() - result);
    }
    else {
        if (result > sizes.size() / 2)
            return (sizes.size() / 2);
        else
            return (sizes.size() - result);
    }
}

auto main() -> int {
    int N;
    std::cin >> N;

    std::vector<int> sizes(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> sizes[i];
    }

    std::sort(sizes.begin(), sizes.end());

    /*for (int i = 0; i < sizes.size(); i++) {
        std::cout << i << "->" << sizes[i] << std::endl;
    }*/
    
    int result = calculateHoldings(sizes, sizes.size() - 1);
    
    std::cout << result << std::endl;
}

/*
* 2 2 4 5 6 7 8 9 
*/