#include <iostream>
#include <queue>

using namespace std;

/* 
we've got 2 options
- making pop costly
- makin push costly (one below)
*/

class QueueStack {
    private: 
        queue<int> q1;
        queue<int> q2;
    public:
        void push(int x);
        int pop();
};

void QueueStack::push(int x) {
    q2.push(x);
    
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    
    // swap names
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

int QueueStack::pop() {
    if (!q1.empty()) {
        int t = q1.front();
        q1.pop();
        return t;
    }
    return -1;
}