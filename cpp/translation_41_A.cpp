#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s1;
    std::string s2;
    std::cin>>s1>>s2;
    std::reverse(s2.begin(), s2.end());
    if(s1 == s2) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
}