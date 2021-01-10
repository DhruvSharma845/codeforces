#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int main() {
    std::string st;
    std::getline(std::cin, st);
    std::set<char> unique_chars; 

    std::for_each(st.begin(), st.end(), [&unique_chars](const char& ch) {
        if(ch != '{' && ch != '}' && ch != ',' && ch != ' ') {
            unique_chars.insert(ch);
        }
    });
    std::cout << unique_chars.size();
}