#include <bits/stdc++.h>
using namespace std;


class Queue {
    private:
        int front_, rear_;
        int capacity, size;
        int *arr;
    public:
        Queue(int x) {
            size = front_ = rear_ = 0;
            capacity = x;
            arr = new int[capacity];
        }

        bool isFull();
        bool isEmpty();
        void enqueue(int x);
        int dequeue();
        int front();
        int rear(); 
};

bool Queue::isFull() {
    return size == capacity;
}

bool Queue::isEmpty() {
    return size == 0;
}

int Queue::front() {
    if (!isEmpty())
        return arr[front_];
    return -1;
}

int Queue::rear() {
    if (!isEmpty())
        return arr[rear_];
    return -1;
}

void Queue::enqueue(int x) {
    if (!isFull()) {
        // if rear_ is last index of array, set it back to 0
        rear_ = rear_ == capacity - 1 ? 0 : rear_ + 1;

        // if it is first item 
        if (isEmpty())
            front_ = rear_;

        arr[rear_] = x;
        size++;
    }
    else {
        cout << "overflow";
        abort();
    }
}

int Queue::dequeue() {
    if (!isEmpty()) {
        int t = arr[front_];

        // if front_ is last index of array, set it back to 0
        front_ = front_ == capacity - 1 ? 0 : front_ + 1;
        size--;
        return t;
    }
    cout << "underflow";
    abort();
}

int main() {
    Queue *q = new Queue(10);

    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);

    cout << q->dequeue() << " dequeued from queue" << endl;
    cout << "Front is " << q->front() << endl;
    cout << "Rear is " << q->rear() << endl;

    return 0;
}