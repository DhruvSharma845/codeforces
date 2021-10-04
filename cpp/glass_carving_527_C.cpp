#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>

using lli = long long int;

auto findMaximumAvailableGlass(int W, int H, 
std::set<int>& horizontalCuts, std::set<int>& verticalCuts, 
char dir, int distance,
std::map<int, int>& horGaps, std::map<int, int>& verGaps) -> lli {
    
    if(dir == 'H') {
        auto rightElementIt = horizontalCuts.lower_bound(distance);
        auto rightElement = *rightElementIt;
        --rightElementIt;
        auto gap = rightElement - (*rightElementIt);

        //std::cout << "Hor gap: " << gap << std::endl;

        if(horGaps.find(gap) != horGaps.end()) {
            horGaps[gap]--;
            if(horGaps[gap] <= 0) {
                horGaps.erase(gap);
            }
        }
        int gap1 = distance - (*rightElementIt);
        horGaps[gap1]++;
        int gap2 = rightElement - distance;
        horGaps[gap2]++;

        horizontalCuts.insert(distance);
    }
    else {
        auto rightElementIt = verticalCuts.lower_bound(distance);
        auto rightElement = *rightElementIt;
        --rightElementIt;
        auto gap = rightElement - (*rightElementIt);
        //std::cout << "Hor gap: " << gap << std::endl;
        if(verGaps.find(gap) != verGaps.end()) {
            verGaps[gap]--;
            if(verGaps[gap] <= 0) {
                verGaps.erase(gap);
            }
        }
        int gap1 = distance - (*rightElementIt);
        verGaps[gap1]++;
        int gap2 = rightElement - distance;
        verGaps[gap2]++;

        verticalCuts.insert(distance);
    }

    //std::cout << maxW << " " << maxH << std::endl;

    return (static_cast<lli>((*(horGaps.rbegin())).first) * (*(verGaps.rbegin())).first);
}

auto main() -> int {
    int W, H, N;
    std::cin >> W >> H >> N;

    std::set<int> horizontalCuts;
    horizontalCuts.insert(0);
    horizontalCuts.insert(H);

    std::set<int> verticalCuts;
    verticalCuts.insert(0);
    verticalCuts.insert(W);

    std::map<int, int> horizontalGaps;
    horizontalGaps[H]++;
    std::map<int, int> verticalGaps;
    verticalGaps[W]++;

    std::string result{""};
    for (int i = 0; i < N; i++) {
        char dir;
        int distance;

        std::cin >> dir >> distance; 
        //std::cout << horizontalCuts.size() << ":" << verticalCuts.size() <<  std::endl;
        std::string res = std::to_string(findMaximumAvailableGlass(W, H, horizontalCuts, verticalCuts, dir, distance, horizontalGaps, verticalGaps));
        result += (res + "\n");
    }

    std::cout << result;
    
}