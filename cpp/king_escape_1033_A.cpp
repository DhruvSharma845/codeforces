//
// Created by dhruv on 16-11-2019.
//
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class KingEscape {
private:
    int dimension;
    pair<int, int> queenPosition;
    pair<int, int> kingPosition;
    pair<int, int> targetPosition;

public:
    KingEscape(int dimension, pair<int, int> queenPosition, pair<int, int> kingPosition, pair<int, int> targetPosition) :
    dimension(dimension), queenPosition(queenPosition), kingPosition(kingPosition), targetPosition(targetPosition)
    { }
    bool canKingReachTarget();
};


bool KingEscape::canKingReachTarget() {

    if(
            (this->queenPosition.first < this->kingPosition.first && this->queenPosition.first > this->targetPosition.first) ||
            (this->queenPosition.first > this->kingPosition.first && this->queenPosition.first < this->targetPosition.first) ||
            (this->queenPosition.second < this->kingPosition.second && this->queenPosition.second > this->targetPosition.second) ||
            (this->queenPosition.second > this->kingPosition.second && this->queenPosition.second < this->targetPosition.second)
    ) {
        return false;
    }

    return true;
}

/*int main() {

    int dimension;
    cin>>dimension;

    int x,  y;

    cin>>x>>y;
    pair<int, int> queenPosition = make_pair(x,y);

    cin>>x>>y;
    pair<int, int> kingPosition = make_pair(x,y);

    cin>>x>>y;
    pair<int, int> targetPosition = make_pair(x,y);

    KingEscape* ke = new KingEscape(dimension, queenPosition, kingPosition, targetPosition);
    if(ke->canKingReachTarget() == true) {
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }

    return 0;
}*/

