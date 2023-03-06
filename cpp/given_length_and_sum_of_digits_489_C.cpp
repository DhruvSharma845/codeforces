#include <iostream>
#include <string>
#include <utility>

std::pair<std::string, std::string> findSmallestAndLargest(int numOfDigits, int sumOfDigits) {
    std::string smallestNum(numOfDigits, '0');
    std::string largestNum(numOfDigits, '0');

    if(sumOfDigits == 0 && numOfDigits != 1) {
        return std::make_pair("-1", "-1");
    }

    int sumOfDigitsForLargest = sumOfDigits;

    --sumOfDigits;
    for(int i = 0; i < numOfDigits - 1; ++i) {
        if(sumOfDigits > 9) {
            smallestNum[numOfDigits - i - 1] = '9';
            sumOfDigits -= 9;
        }
        else {
            char c = static_cast<char>(sumOfDigits + 48);
            smallestNum[numOfDigits - i - 1] = c;
            sumOfDigits = 0;
            break;
        }
    }
    ++sumOfDigits;
    if(sumOfDigits > 9) {
        return std::make_pair("-1", "-1");
    }
    char c = static_cast<char>(sumOfDigits + 48);
    smallestNum[0] = c;

    for(int i = 0; i < numOfDigits; ++i) {
        if(sumOfDigitsForLargest > 9) {
            largestNum[i] = '9';
            sumOfDigitsForLargest -= 9;
        }
        else {
            char c = static_cast<char>(sumOfDigitsForLargest + 48);
            largestNum[i] = c;
            sumOfDigitsForLargest = 0;
            break;
        }
    }

    if(sumOfDigitsForLargest > 0) {
        return std::make_pair("-1", "-1");
    }

    return std::make_pair(smallestNum, largestNum);
}

auto main() -> int {
    int m, s;
    std::cin >> m >> s;

    auto pr = findSmallestAndLargest(m, s);
    std::cout << pr.first << " " << pr.second << std::endl;
    
    return 0;
}