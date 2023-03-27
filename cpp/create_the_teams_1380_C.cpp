#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
#include <algorithm>

using lli = long long int;

auto calculateMaxTeams(std::vector<int>& skills, int minLimit) -> int {
    std::sort(skills.begin(), skills.end(), std::greater<int>());

    lli currentTeamSize = 0;
    int numOfTeams = 0;
    for (int i = 0; i < skills.size(); ++i) {
        ++currentTeamSize;
        if(currentTeamSize * static_cast<lli>(skills[i]) >= minLimit) {
            ++numOfTeams;
            currentTeamSize = 0;
        }
    }
    return numOfTeams;
}

auto main() -> int {
    int T;
    std::cin >> T;

    std::stringstream ss{""};

    for (int i = 0; i < T; ++i) {
        int N, X;
        std::cin >> N >> X;

        std::vector<int> skills;
        skills.reserve(N);
        for(int j = 0; j < N; ++j) {
            int x;
            std::cin >> x;
            skills.push_back(x);
        }
        ss << calculateMaxTeams(skills, X) << "\n";
    }
    std::cout << ss.str();
}