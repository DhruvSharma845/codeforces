//
// Created by dhruv on 09-12-2019.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ArraySegmenter {
public:
    int findMaxNumberOfCuts(int N, int* nums, int B);

    vector<int>* findAllCutValues(int N, int *nums);
};

int ArraySegmenter::findMaxNumberOfCuts(int N, int *nums, int B) {

    vector<int>* cutValues = this->findAllCutValues(N, nums);
    if(cutValues->empty()) {
        return 0;
    }
    sort((*cutValues).begin(), (*cutValues).end());

    int bitcoins = 0;
    int count = 0;
    for (auto v : *cutValues) {
        if(bitcoins + v > B) {
            break;
        }
        bitcoins += v;
        count++;
    }
    return count;
}

vector<int>* ArraySegmenter::findAllCutValues(int N, int *nums) {
    vector<int>* cutValues = new vector<int>();

    int odds = 0, evens = 0;
    for (int i = 0; i < N; ++i) {
        if(nums[i] % 2 == 0) {
            evens++;
        }
        else {
            odds++;
        }

        if(odds == evens && i != (N-1)) {
            cutValues->push_back(abs(nums[i] - nums[i+1]));
        }
    }

    return cutValues;

}

int main() {
    int N, B;
    cin>>N>>B;

    int* nums = new int[N];
    for (int i = 0; i < N; ++i) {
        cin>>nums[i];
    }

    ArraySegmenter* as = new ArraySegmenter();
    cout<<as->findMaxNumberOfCuts(N, nums, B);

    return 0;
}
