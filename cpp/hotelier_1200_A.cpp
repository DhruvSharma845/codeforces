#include <iostream>

using namespace std;

enum Direction {
    LEFT, RIGHT
};

class Hotel {
private:
    int numOfEvents;
    string events;
    int* assignmentList;

    void assignClosestRoom(Direction dir);
public:
    Hotel(int _n, string _e) : numOfEvents(_n), events(_e) {
        this->assignmentList = new int[10];
        for (int i = 0; i < 10; ++i) {
            this->assignmentList[i] = 0;
        }
    }

    int* getAssignmentList();
};

void Hotel::assignClosestRoom(Direction dir) {
    if(dir == LEFT) {
        for (int i = 0; i < 10; ++i) {
            if(this->assignmentList[i] == 0) {
                this->assignmentList[i] = 1;
                break;
            }
        }
    }
    else {
        for (int i = 9; i >= 0; --i) {
            if(this->assignmentList[i] == 0) {
                this->assignmentList[i] = 1;
                break;
            }
        }
    }
}

int* Hotel::getAssignmentList() {

    for (const char ch: this->events) {
        switch (ch) {
            case 'L':
                this->assignClosestRoom(LEFT);
                break;
            case 'R':
                this->assignClosestRoom(RIGHT);
                break;
            default:
                this->assignmentList[ch - '0'] = 0;
        }
    }
    return assignmentList;
}

/*int main() {

    int numOfEvents;
    cin>>numOfEvents;

    string events;
    cin>>events;

    Hotel* hotel = new Hotel(numOfEvents, events);
    int* assignmentList = hotel->getAssignmentList();
    for (int i = 0; i < 10; ++i) {
        cout<<assignmentList[i];
    }

    return 0;
}*/
