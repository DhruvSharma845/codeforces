//
// Created by dhruv on 16-11-2019.
//
#include <iostream>
using  namespace std;

bool canTwoArraysBeMadeEqual(int N, int* source, int* target) {
    int* diff = new int[N];
    for (int i = 0; i < N; ++i) {
        diff[i] = target[i] - source[i];
    }

    int start = -1, end = -1;
    int amount = -1;
    for (int i = 0; i < N; ++i) {
        if (diff[i] < 0) {
            return false;
        }
        if(diff[i] > 0 ) {
            if(start == -1) {
                amount = diff[i];
                start = i;
            }
            else if(end != -1 || amount != diff[i]) {
                return false;
            }
        }

        if(diff[i] == 0 && start != -1) {
            end = i-1;
        }
    }

    return true;
}

int main() {
    int T;
    cin>>T;
    for (int i = 0; i < T; ++i) {
        int N;
        cin>>N;

        int* source = new int[N];
        int* target = new int[N];

        for (int j = 0; j < N; ++j) {
            cin>>source[j];
        }
        for (int k = 0; k < N; ++k) {
            cin>>target[k];
        }

        bool res = canTwoArraysBeMadeEqual(N, source, target);
        if(res) {
            cout<<"YES"<<"\n";
        }
        else {
            cout<<"NO"<<"\n";
        }

    }
    return 0;
}
