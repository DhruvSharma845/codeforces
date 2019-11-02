//
// Created by dhruv on 02-11-2019.
//
#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <utility>
using namespace std;

class GoodSubsequence {
private:
    string s;
    int k;
public:
    GoodSubsequence(string _s, int _k) : s(std::move(_s)), k(_k) {}
    int findLengthOfLongestGoodSubsequence();
};

int GoodSubsequence::findLengthOfLongestGoodSubsequence() {
    int indexedTable[26] = { 0 };
    for(char const &c : this->s) {
        indexedTable[ c - 65 ] += 1;
    }

    int minChars = INT_MAX;
    for(int j = 0; j < this->k; j++) {
        minChars = min(minChars, indexedTable[j]);
    }
    return minChars * this->k;
}

/*int main(void) {
    int strLength;
    cin>>strLength;

    int k;
    cin>>k;

    string s;
    cin>>s;

    GoodSubsequence* gs = new GoodSubsequence(s, k);
    cout<<gs->findLengthOfLongestGoodSubsequence();

    return 0;
}*/
