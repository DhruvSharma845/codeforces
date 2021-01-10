#include <iostream>
#include <vector>
#include <algorithm>

class LaptopInfo {
public:
    int price;
    int quality;

    LaptopInfo(): price{0}, quality{0} 
    {}

    LaptopInfo(int _price, int _quality) : price{_price}, quality{_quality} 
    {}
};

int main() {
    int N;
    std::cin >> N;

    std::vector<LaptopInfo*> vec;
    for(int i = 0; i < N; ++i) {
        int p;
        int q;
        std::cin >> p >> q;
        vec.emplace_back(new LaptopInfo(p, q));
    }

    std::sort(vec.begin(), vec.end(), [](LaptopInfo* a, LaptopInfo* b){
        return a->price < b->price;
    });

    bool isHappy = false;
    for(int i = 0; i < (N-1); ++i) {
        if(vec[i]->quality > vec[i+1]->quality) {
            isHappy = true;
            break;
        }
    }
    if(isHappy == true) {
        std::cout << "Happy Alex" << std::endl;
    }
    else {
        std::cout << "Poor Alex" << std::endl;
    }
}