//
// Created by dhruv on 16-11-2019.
//

#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

class OathOfNightWatch {
private:
    long int* arr;
    int sz;
public:
    OathOfNightWatch(long int *arr, int sz) : arr(arr), sz(sz) {}
    int findCountOfMinAndMaxElements();
};

int OathOfNightWatch::findCountOfMinAndMaxElements() {
    unordered_map<long int, int> countMap;
    long int minElement = LONG_MAX;
    long int maxElement = LONG_MIN;
    for (int i = 0; i < this->sz; ++i) {
        if(this->arr[i] <= minElement) {
           minElement = this->arr[i];
        }
        if(this->arr[i] >= maxElement) {
            maxElement = this->arr[i];
        }

        if(countMap.find(this->arr[i]) == countMap.end()) {
            countMap.insert(make_pair(this->arr[i], 1));
        }
        else {
            int val = countMap[this->arr[i]];
            countMap[this->arr[i]] = val + 1;
        }
    }

    if(minElement != maxElement) {
        return (countMap[minElement] + countMap[maxElement]);
    }
    return this->sz;
}

/*int main() {
    int N;
    cin>>N;

    long int* arr = new long int[N];
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    OathOfNightWatch* onw = new OathOfNightWatch(arr, N);
    cout<<(N - onw->findCountOfMinAndMaxElements());

    return 0;
}*/

