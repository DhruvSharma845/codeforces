#include <iostream>
#include <vector>
#include <algorithm>

int findMaxBooksThatCanBeRead(int freeMins, const std::vector<int>& minsOfBooks) {
    int start = 0;
    int end = 0;

    int maxBooks = 0;
    int currentMins = 0;
    while(end < minsOfBooks.size() && start <= end) {
        if(currentMins + minsOfBooks[end] <= freeMins) {
            currentMins += minsOfBooks[end];
            maxBooks = std::max(maxBooks, end - start + 1);
            ++end;
        }
        else {
            if(currentMins > 0) {
                currentMins -= minsOfBooks[start];
            }
            else {
                ++end;
            }
            ++start;
        }
    }
    return maxBooks;
}

auto main() -> int {
    int numOfBooks;
    int freeMins;
    std::cin >> numOfBooks >> freeMins;

    std::vector<int> minsToRead;
    minsToRead.reserve(numOfBooks);
    for (int i = 0; i < numOfBooks; ++i) {
        int mins;
        std::cin >> mins;
        minsToRead.push_back(mins);
    }
    
    std::cout << findMaxBooksThatCanBeRead(freeMins, minsToRead) << std::endl;

    return 0;
}