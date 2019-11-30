//
// Created by dhruv on 23-11-2019.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Transformer {
public:
    vector<int>& transformAtoB(int a, int b);
};

vector<int>& Transformer::transformAtoB(int a, int b) {

    vector<int>* vec = new vector<int>();
    vec->push_back(b);
    while(b != a) {
        if(b < a) {
            vec->clear();
            break;
        }
        if(b % 2 == 0) {
            b = b / 2;
        }
        else if(b % 10 == 1) {
            b = b / 10;
        }
        else {
            vec->clear();
            break;
        }
        vec->push_back(b);
    }
    if(b != a) {
        vec->push_back(-1);
    }
    return (*vec);
}

/*int main() {
    int A, B;
    cin>>A>>B;

    Transformer* t = new Transformer();
    vector<int> res = t->transformAtoB(A, B);

    if(res.size() == 1 and res[0] == -1) {
        cout<<"NO";
    }
    else {
        cout<<"YES\n";
        cout<<res.size()<<"\n";
        reverse(res.begin(), res.end());
        for (auto const& i: res) {
            cout<<i<<" ";
        }
    }

    return 0;
}*/

