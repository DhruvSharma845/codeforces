#include <iostream>
#include <vector>
#include <algorithm>

auto main() -> int {
    std::string str;
    std::cin >> str;

    int M;
    std::cin >> M;

    std::vector<int> trans(M, 0);
    for (int i = 0; i < M; ++i) {
        std::cin >> trans[i];
    }
   
    std::sort(trans.begin(), trans.end());

    int count = 1;
    int transIndex = 1;
    for(int i = trans[0] - 1; i < str.length() / 2; ++i) {
        while(transIndex < trans.size() && trans[transIndex] - 1 == i) {
            ++transIndex;
            ++count;
        }
        if(count % 2 == 1) {
            std::swap(str[i], str[str.length() - i - 1]);
        }
    }
    std::cout << str << std::endl;
}