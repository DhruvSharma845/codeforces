#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::string sequence;
    std::cin >> sequence;

    std::stringstream seq_stream(sequence);
    std::string token;
    std::vector<int> pages;
    while(getline(seq_stream, token, ',')) {
        pages.push_back(stoi(token));
    }

    std::sort(pages.begin(), pages.end());

    //std::copy(pages.begin(), pages.end(), std::ostream_iterator<int>(std::cout, " "));
    
    std::string finalSequence;
    int currentPage = pages[0];
    int start = currentPage, end = currentPage;
    int currentIndex = 1;
    while(currentIndex < pages.size()) {
        if(pages[currentIndex] == currentPage) {
            ++currentIndex;
            end = currentPage;
        }
        else if(pages[currentIndex] == currentPage + 1) {
            currentPage = pages[currentIndex++];
            end = currentPage;
        }
        else {
            finalSequence += ((finalSequence.empty() ? "" : ",") + std::to_string(start) + ((start != currentPage) ? "-" +  std::to_string(currentPage): ""));
            start = end = currentPage = pages[currentIndex++];
        }
    }
    finalSequence += ((finalSequence.empty() ? "" : ",") + std::to_string(start) + ((start != currentPage) ? "-" +  std::to_string(currentPage): ""));

    std::cout << finalSequence << std::endl;
}