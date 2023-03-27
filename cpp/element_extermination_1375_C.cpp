#include <iostream>
#include <vector>
#include <string>
#include <sstream>

auto checkIfShrinkIsPossible(const std::vector<int>& arr) {
    std::vector<int> st;

    for (int i = 0; i < arr.size(); ++i) {
        st.push_back(arr[i]);
        while(st.size() >= 2 && st[st.size() - 2] < st[st.size() -1]) {
            int second = st.back();
            st.pop_back();
            int first = st.back();
            st.pop_back();
            if(st.empty()) {
                st.push_back(first);
            }
            else {
                st.push_back(second);
            }
        }
    }
    if(st.size() == 1) {
        return true;
    }
    else {
        return false;
    }
}

auto main() -> int {
    int T;
    std::cin >> T;

    std::stringstream ss{""};

    for (int i = 0; i < T; ++i) {
        int N;
        std::cin >> N;
        std::vector<int> arr;
        arr.reserve(N);

        for (int j = 0; j < N; ++j) {
            int x;
            std::cin >> x;
            arr.push_back(x);
        }
        
        if(checkIfShrinkIsPossible(arr) == true) {
            ss << "YES\n";
        }
        else {
            ss << "NO\n";
        }
    }
    std::cout << ss.str();
}