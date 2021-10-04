#include <bits/stdc++.h>

using namespace std;

// implementation making enqueue opertions costly
class Queue {
    private:
        stack<int> s1, s2;
    public:
        void enQueue(int x) {
            // move all elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            // push item into s1
            s1.push(x);

            // push all elements back to s1
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        int deQueue() {
            if (!s1.empty()) {
                int t = s1.top();
                s1.pop();
                return t;
            }
            cout << "underflow" << endl;
            abort();
        }
};

int main() {
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
 
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}