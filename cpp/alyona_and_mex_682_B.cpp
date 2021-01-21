#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> nums(N);
    for (size_t i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

    int currentMex = 1;
    for (size_t i = 0; i < N;) {
        if(nums[i] == currentMex) {
            ++i;
            ++currentMex;
        }
        else if(nums[i] > currentMex) {
            nums[i] = currentMex;
            ++currentMex;
            ++i;
        }
        else {
            ++i;
        }
    }
    
    std::cout << currentMex << std::endl;
    
}