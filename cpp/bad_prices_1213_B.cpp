//
// Created by dhruv on 17-11-2019.
//
#include <iostream>
#include <limits>

using namespace std;

class BadPriceFinder {
private:
    int sz;
    int* prices;
public:
    BadPriceFinder(int sz, int *prices) : sz(sz), prices(prices) {}

    int findCountOfBadPriceDays();

};

int BadPriceFinder::findCountOfBadPriceDays() {
    int minE = -1;
    int count = 0;
    for (int i = this->sz - 1; i >= 0 ; --i) {
        if(minE != -1 && this->prices[i] > minE) {
            count++;
        }
        if(minE == -1 || this->prices[i] < minE) {
            minE = this->prices[i];
        }
    }
    return count;
}

/*int main() {
    int T;
    cin>>T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin>>N;

        int* prices = new int[N];
        for (int j = 0; j < N; ++j) {
            cin>>prices[j];
        }

        BadPriceFinder* bpf = new BadPriceFinder(N, prices);
        cout<<bpf->findCountOfBadPriceDays()<<"\n";

    }
    return 0;
}*/

