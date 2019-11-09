//
// Created by dhruv on 03-11-2019.
//

#include <iostream>
#include <limits>

using namespace std;

class LongestIncreasingSubSegment {
private:
    int* arr;
    int size;
public:
    LongestIncreasingSubSegment(int* _arr, int _size): arr(_arr), size(_size) {}

    int findLengthOfLongestIncreasingSubSegment();
};

int LongestIncreasingSubSegment::findLengthOfLongestIncreasingSubSegment() {
    int currentMax = numeric_limits<int>::min();
    int count = 1;
    for (int i = 1; i < this->size; ++i) {
        if(this->arr[i] >= this->arr[i-1]) {
            count++;
            if(count > currentMax) {
                currentMax = count;
            }
        }
        else {
            count = 1;
        }
    }
    return max(currentMax, count);
}

/*int main() {
    int N;
    cin>>N;

    int* arr = new int[N];
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }

    LongestIncreasingSubSegment* lis = new LongestIncreasingSubSegment(arr, N);
    cout<<lis->findLengthOfLongestIncreasingSubSegment();

    return 0;
}*/

