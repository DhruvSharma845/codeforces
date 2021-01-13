#include <iostream>
#include <algorithm>
#include <cmath>


int main() {
    int T;
    std::cin >> T;

    for(int i = 0; i < T; ++i) {
        int N;
        std::cin >> N;

        int moves = (N-1);

        int lim = static_cast<int>(sqrt(N));
        for(int j = 2; j <= lim; ++j) {
            int currentMoves = (j-1) + (N/j) - 1 + ((N%j) > 0 ? 1 : 0);
            //std::cout << j << " " << currentMoves << std::endl;
            moves = std::min(moves, currentMoves);
        }
        std::cout << moves << std::endl;
    }
}