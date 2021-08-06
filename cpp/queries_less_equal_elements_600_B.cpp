#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

auto findFloorOfElement(const std::vector<int>& A, int key) -> int {
    int low = 0, high = A.size() - 1;
    int fl = -1;
    while(low <= high) {
        auto mid = low + (high - low) / 2;
        if(A[mid] == key) {
            if((mid + 1) <= high && A[mid + 1] == A[mid]) {
                fl = mid;
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        else if(A[mid] > key) {
            high = mid - 1;
        }
        else {
            fl = mid;
            low = mid + 1;
        }
    }
    return fl;
}

auto main() -> int {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    std::string res{""};
    for (int i = 0; i < M; i++) {
        int x;
        std::cin >> x;
        int r = findFloorOfElement(A, x);
        res += (std::to_string(r + 1) + " ");
    }
    std::cout << res << std::endl;
}