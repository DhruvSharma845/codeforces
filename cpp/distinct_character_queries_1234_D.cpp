#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

auto main() -> int {

    std::string s;
    std::cin >> s;

    std::unordered_map<char, std::set<int>> indicesMap;
    for(auto i = 0; i < s.length(); i++) {
        indicesMap[s.at(i)].insert(i);
    }

    int q;
    std::cin >> q;

    for(int i = 0; i < q; i++) {
        int queryType;
        std::cin >> queryType;

        if(queryType == 1) {
            int pos;
            std::cin >> pos;
            --pos;

            char c;
            std::cin >> c;

            indicesMap[s.at(pos)].erase(pos);
            s[pos] = c;
            indicesMap[s.at(pos)].insert(pos);
        }
        else if(queryType == 2) {
            int l, r;
            std::cin >> l >> r;

            --l;
            --r;
            int count = 0;
            for(int i = 0; i < 26; i++) {
                char c = static_cast<char>(i + 97);
                if(indicesMap.find(c) != indicesMap.end()) {
                    auto& st = indicesMap[c];
                    auto it = st.lower_bound(l);
                    if(it != st.end() && *it <= r) {
                        //std::cout << "For char " << c << " Found at: " << *it << std::endl;
                        count++;
                    }
                }
            }
            std::cout << count << std::endl;
        }
    }
}
