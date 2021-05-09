#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using lli = long long int;

auto findUnfairness(const lli& elem, std::unordered_map<lli, lli>& table) -> lli {
    if(table.find(elem) != table.end()) {
        return table.at(elem);
    }
    auto pw = static_cast<lli>(log2(elem));
    auto powerOfTwo = static_cast<lli>(pow(2, pw));
    auto rem = elem - powerOfTwo;
    if(rem < 0) {
        powerOfTwo = static_cast<lli>(pow(2, pw - 1));
        rem = elem - powerOfTwo;
    }
    return table.at(powerOfTwo) + findUnfairness(rem, table);
}

void fillUnfairnessTable(const std::vector<lli>& queries, std::unordered_map<lli, lli>& table) {
    auto index = 0;
    auto i = lli{0};
    while(index < queries.size()) {
        auto currentPowerOfTwo = static_cast<lli>(pow(2, i));
        table[currentPowerOfTwo] = static_cast<lli>(pow(2, i + 1)) - 1;
        while(index < queries.size() && queries[index] < currentPowerOfTwo) {
            if(table.find(queries[index]) == table.end()) {
                table.emplace(queries[index], findUnfairness(queries[index], table));
            }
            ++index;
        }
        ++i;
    }
}

auto main() -> int {
    auto T = int{0};
    std::cin >> T;

    std::vector<lli> queries;
    for (auto i = 0; i < T; ++i) {
        auto num = lli{0};
        std::cin >> num;
        queries.push_back(num);
    }

    std::vector<lli> q(queries);
    std::sort(q.begin(), q.end());

    std::unordered_map<lli, lli> table;
    fillUnfairnessTable(q, table);

    for(auto i = 0; i < T; ++i) {
        std::cout << table[queries[i]] << std::endl;
    } 

}