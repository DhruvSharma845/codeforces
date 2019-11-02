//
// Created by dhruv on 02-11-2019.
//

#include <iostream>

int calculatePairs(int count, int *memoizedCount);

using namespace std;

int findNumberOfPairs(int sideLength) {
    int* rowCount = new int[sideLength];
    int* colCount = new int[sideLength];
    int* memoizedCount = new int[sideLength + 1];

    for(int i = 0; i < sideLength; i++) {
        rowCount[i] = colCount[i] = 0;
        memoizedCount[i] = -1;
    }
    memoizedCount[sideLength] = -1;

    for(int row = 0; row < sideLength; row++) {
        string s;
        cin>>s;
        for(string::size_type col=0; col < s.size(); col++) {
            if(s[col] == 'C') {
                rowCount[row]++;
                colCount[col]++;
            }
        }
    }

    int total = 0;
    // calculating for rows
    for(int i = 0; i < sideLength; i++) {
        total += calculatePairs(rowCount[i],memoizedCount);
    }

    //calculating for columns
    for(int i = 0; i < sideLength; i++) {
        total += calculatePairs(colCount[i], memoizedCount);
    }

    return total;
}

int calculatePairs(int count, int *memoizedCount) {
    if(count == 0) {
        return 0;
    }
    if(memoizedCount[count] == -1) {
        memoizedCount[count] = (count * (count - 1))/2;
    }
    return memoizedCount[count];
}

/*int main(void) {

    int sideLength;
    cin>>sideLength;

    cout<<findNumberOfPairs(sideLength);

    return 0;
}*/


