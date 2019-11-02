//
// Created by dhruv on 02-11-2019.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class PalindromicSuperSequenceFinder {
public:
    static string& findPalindromicSuperSequence(string& s, string& resStr);
};

string& PalindromicSuperSequenceFinder::findPalindromicSuperSequence(string &s, string& resStr) {
    string::size_type start = 0, end = s.size() - 1;

    string firstHalf, secondHalf;
    firstHalf = secondHalf = "";

    while(start < end) {
        if(s[start] == s[end]) {
            firstHalf.push_back(s[start]);
            secondHalf.push_back(s[end]);
            start++;
            end--;
        }
        else {
            firstHalf.push_back(s[start]);
            secondHalf.push_back(s[start]);
            start++;
        }
    }
    if(start == end) {
        firstHalf.push_back(s[start]);
    }
    resStr = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end());
    resStr += secondHalf;
    return resStr;
}

/*int main(void) {

    string s;
    cin>>s;

    string resStr = "";
    PalindromicSuperSequenceFinder::findPalindromicSuperSequence(s, resStr);
    cout<<resStr;
    return 0;
}*/

