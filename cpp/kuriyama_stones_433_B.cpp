//
// Created by dhruv on 30-11-2019.
//

#include <iostream>
#include <algorithm>

using namespace std;

class CumulativeSum {
private:
    long long int* sequentialCumulativeSums;
    long long int* orderedCumulativeSums;
public:
    CumulativeSum(int n, int* arr);
    long long int getSequentialSum(int low, int high);
    long long int getOrderedSum(int low, int high);
};

CumulativeSum::CumulativeSum(int n, int *arr) {
    this->sequentialCumulativeSums = new long long int[n];
    this->orderedCumulativeSums = new long long int[n];
    this->sequentialCumulativeSums[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        this->sequentialCumulativeSums[i] = arr[i] + this->sequentialCumulativeSums[i - 1];
    }

    sort(arr, arr + n);
    this->orderedCumulativeSums[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        this->orderedCumulativeSums[i] = arr[i] + this->orderedCumulativeSums[i - 1];
    }
}

long long int CumulativeSum::getSequentialSum(int low, int high) {
    if(low > 0) {
        return this->sequentialCumulativeSums[high] - this->sequentialCumulativeSums[low - 1];
    }
    else {
        return this->sequentialCumulativeSums[high];
    }
}

long long int CumulativeSum::getOrderedSum(int low, int high) {
    if(low > 0) {
        return this->orderedCumulativeSums[high] - this->orderedCumulativeSums[low - 1];
    }
    else {
        return this->orderedCumulativeSums[high];
    }
}

/*int main() {

    int numOfStones;
    cin>>numOfStones;

    int* costs = new int[numOfStones];
    for (int i = 0; i < numOfStones; ++i) {
        cin>>costs[i];
    }

    CumulativeSum* cs = new CumulativeSum(numOfStones, costs);

    int numOfQueries;
    cin>>numOfQueries;

    for (int j = 0; j < numOfQueries; ++j) {
        int type;
        cin>>type;
        int l, r;
        cin>>l>>r;
        if(type == 1) {
            cout<<cs->getSequentialSum(l - 1, r - 1)<<"\n";
        }
        else if(type == 2) {
            cout<<cs->getOrderedSum(l - 1, r - 1)<<"\n";
        }
    }

    return 0;
}*/
