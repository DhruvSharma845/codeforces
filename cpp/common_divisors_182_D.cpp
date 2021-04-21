#include <iostream>
#include <string>

auto findCommonDivisors(const std::string& str1, const std::string& str2) -> int {
    int numDivisors = 0; 
    for(auto index = 1; index <= str1.length(); ++index) {
        bool isEqual = true;
        if(index < str1.length()) {
            if(str1[index] != str1[0]) {
                continue;
            }
            if(str1.length() % index != 0) {
                continue;
            }

            for(auto split = 1; split < str1.length() / index; ++split) {
                for(auto first = 0, second = index * split; first < index; ++first, ++second) {
                    if(str1[first] != str1[second]) {
                        isEqual = false;
                        break;
                    }
                }
                if(isEqual == false) {
                    break;
                }
            }
        }
        if(isEqual == true) {
            if(str2.length() % index != 0) {
                continue;
            }
            bool isEqual2 = true;
            for(auto split = 0; split < str2.length() / index; ++split) {
                for(auto first = 0, second = index * split; first < index; ++first, ++second) {
                    if(str1[first] != str2[second]) {
                        isEqual2 = false;
                        break;
                    }
                }
                if(isEqual2 == false) {
                    break;
                }
            }
            if(isEqual2 == true) {
                ++numDivisors;
            }
        }
    }

    return numDivisors;
}

auto main() -> int {

    std::string str1;
    std::string str2;

    std::cin >> str1;
    std::cin >> str2;

    if(str1.length() <= str2.length()) {
        std::cout << findCommonDivisors(str1, str2) << std::endl;
    }
    else {
        std::cout << findCommonDivisors(str2, str1) << std::endl;
    }
}