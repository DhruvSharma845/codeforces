#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    long long int L, R, K, X, Y;
    std::cin >> L >> R >> X >> Y >> K;

    bool res = false;
    for(int i = X; i <= Y; ++i) {
        if(K * i >= L && K * i <= R) {
            res = true;
            break;
        }
    }

    if(res) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
}