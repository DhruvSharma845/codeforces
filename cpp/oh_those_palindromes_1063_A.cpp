#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::string str;
    std::cin >> str;

    std::sort(str.begin(), str.end());

    std::cout << str << std::endl;
}


