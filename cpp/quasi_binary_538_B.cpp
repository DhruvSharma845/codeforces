#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>

auto findMinimumQuasiBinaryNumbers(int N) -> std::vector<int> {
    int temp = N;
    int maxDigit = 0;

    std::stack<int> st;
    while(temp != 0) {
        int digit = temp % 10;
        st.push(digit);
        maxDigit = std::max(maxDigit, digit);
        temp /= 10;
    }
    std::vector<int> res(maxDigit, 0);

    while(!st.empty()) {
        int dig = st.top();
        st.pop();
        int i = 0;
        for(; i < dig; ++i) {
            res[i] = (res[i] * 10) + 1;
        }
        for(; i < res.size(); ++i) {
            res[i] *= 10;
        }
    }
    return res;
}

auto main() -> int {
    int N;
    std::cin >> N;

    auto res = findMinimumQuasiBinaryNumbers(N);
    std::cout << res.size() << std::endl;
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}