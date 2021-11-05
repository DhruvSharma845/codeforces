#include <iostream>
#include <string>
#include <vector>
#include <set>

auto findNewspaperHeadingsToConvert(const std::string& initialHeading, const std::string& requiredString) -> int {
    std::vector<std::set<int>> charLocations(26);

    for(int i = 0; i < initialHeading.size(); ++i) {
        int charInt = static_cast<int>(initialHeading[i]) - 97;
        charLocations[charInt].insert(i);
    }

    int prevIndex = -1;
    int requiredHeadings = 0;
    for(int i = 0; i < requiredString.size(); ++i) {
        int charInt = static_cast<int>(requiredString[i]) - 97;
        if(charLocations[charInt].empty()) {
            return -1;
        }
        if(prevIndex == -1) {
            prevIndex = *(charLocations[charInt].begin());
            ++requiredHeadings;
        }
        else {
            auto& tempSet = charLocations[charInt];
            auto it = tempSet.upper_bound(prevIndex);
            if(it != tempSet.end()) {
                prevIndex = *it;
            }
            else {
                prevIndex = *(charLocations[charInt].begin());
                ++requiredHeadings;
            }
        }
    }
    return requiredHeadings;
}

auto main() -> int {
    std::string initialHeading;
    std::cin >> initialHeading;

    std::string requiredString;
    std::cin >> requiredString;

    std::cout << findNewspaperHeadingsToConvert(initialHeading, requiredString) << std::endl;
}