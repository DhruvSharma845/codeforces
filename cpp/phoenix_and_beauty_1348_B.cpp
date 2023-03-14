#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iterator>

auto findBeautifulArray(const std::vector<int>& arr, int K) -> std::vector<int> {
    std::unordered_set<int> uniqueElems;
    for(const auto& elem: arr) {
        uniqueElems.insert(elem);
    }
    std::vector<int> res;
    if(uniqueElems.size() > K) {
        return res;
    }
    res.reserve(arr.size() * K);

    for(int i = 0; i < arr.size(); ++i) {
        for(const auto& elem: uniqueElems) {
            res.push_back(elem);
        }
        for(int j = 0; j < K - uniqueElems.size(); ++j) {
            res.push_back(1);
        }
    }
    return res;
}

auto main() -> int {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> arr;
        arr.reserve(n);
        for (int j = 0; j < n; ++j) {
            int e;
            std::cin >> e;
            arr.push_back(e);
        }
        auto bArr = findBeautifulArray(arr, k);
        if(bArr.size() > 0) {
            std::cout << bArr.size() << std::endl;
            std::copy(bArr.begin(), bArr.end(), std::ostream_iterator<int>(std::cout, " "));
        }
        else {
            std::cout << "-1" << std::endl;
        }
    }
    
    return 0;
}