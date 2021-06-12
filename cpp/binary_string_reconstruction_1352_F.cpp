/*
3 8 3
0000101010101111
00001111 0101010

1 3 5
0010111111
0011111101

3 1 2
0000111

0 2 3
111101

3 2 0
000010

9
1 3 5
1 1 1
3 9 3
0 1 0
3 1 2
0 0 3
2 0 0
0 2 3
3 2 0
*/

#include <iostream>

auto constructBinaryString(int zeroes, int ones, int twos) -> void {
    std::string zeroString{""};
    if(zeroes != 0) {
        zeroString = std::string(zeroes + 1, '0');
    }
    std::string oneString{""};
    if(twos != 0) {
        oneString = std::string(twos + 1, '1');
    }
    std::string alternativeString{""};
    if(ones >= 1) {
        char currentChar = '0';
        if(zeroes != 0 && twos != 0) {
            ones--;
        }
        else if(zeroes != 0) {
            currentChar = '1';
        }
        else if(zeroes == 0 && twos == 0) {
            ones++;
        }
        
        for (int i = 0; i < ones; i++) {
            alternativeString.push_back(currentChar);
            currentChar = (currentChar == '0') ? '1' : '0';
        }
    }
    std::cout << zeroString + oneString + alternativeString << std::endl;
}

auto main() -> int {
    auto T = int{0};
    std::cin >> T;
    for (size_t i = 0; i < T; i++) {
        int zeroes, ones, twos;
        std::cin >> zeroes >> ones >> twos;
        constructBinaryString(zeroes, ones, twos);
    }
}