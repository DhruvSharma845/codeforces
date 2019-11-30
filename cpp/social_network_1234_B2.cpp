//
// Created by dhruv on 30-11-2019.
//
#include <iostream>
#include <deque>
#include <map>

using namespace std;

class MessageWindow {
public:
    deque<int>* findMessageWindowAfterMessages(int windowSize, int numOfMessages);
};

deque<int>* MessageWindow::findMessageWindowAfterMessages(int windowSize, int numOfMessages) {

    int* messagesIds = new int[numOfMessages];

    deque<int>* window = new deque<int>();
    map<int, int> elementsVisible;

    int currentWindowSize = 0;
    for (int i = 0; i < numOfMessages; ++i) {
        cin>>messagesIds[i];
        if(elementsVisible[messagesIds[i]] == 0) {
            if(currentWindowSize < windowSize) {
                window->push_front(messagesIds[i]);
                currentWindowSize++;
            }
            else {
                int lastElement = window->back();
                window->pop_back();
                elementsVisible[lastElement] = 0;
                window->push_front(messagesIds[i]);
            }
            elementsVisible[messagesIds[i]] = 1;
        }
    }
    return window;
}


int main() {
    int numOfMessages, messagesVisible;
    cin>>numOfMessages>>messagesVisible;


    MessageWindow* mw = new MessageWindow();
    deque<int>* window = mw->findMessageWindowAfterMessages(messagesVisible, numOfMessages);

    cout<<window->size()<<"\n";
    for (auto it = window->begin(); it != window->end(); it++) {
        cout<<(*it)<<" ";
    }
    return 0;
}
