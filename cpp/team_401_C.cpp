#include <iostream>
#include <string>

auto findArrangementOfCards(int N, int M) -> std::string {
    if(N > M + 1) {
        return std::string{"-1"};
    }

    int maxM = 4 + (N-1) * 2;
    if(M > maxM) {
        return std::string{"-1"};
    }

    std::string res{""};
    if(M > N) {
        if(M > N + 1) {
            res += "11";
            M -= 2;
        }
        else {
            res += "1";
            --M;
        }
    }
    int countOfDoubleOnes = (M > N) ? M - N: 0;
    while(N > 0 && M > 0) {
        if(countOfDoubleOnes > 0) {
            res += "011";
            --countOfDoubleOnes;
            --N;
            M -= 2;
        }
        else {
            res += "01";
            --N;
            --M;
        }
    }
    if(N > 0 && M <= 0) {
        res += "0";
    }
    return res;
}

auto main() -> int {
    int N, M;
    std::cin >> N >> M;

    std::cout << findArrangementOfCards(N, M) << std::endl;
    return 0;
}