#include <bits/stdc++.h>
using namespace std;

struct QueueNodeLL {
    int data;
    QueueNodeLL *next;

    QueueNodeLL(int x){
        data = x;
        next = NULL;
    }
};

class Queue {
    private:
        QueueNodeLL *rear_, *front_;
        int capacity, size;
    public:
        Queue(int x) {
            size = 0;
            capacity = x;
            rear_ = front_ = NULL;
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
    if (!isEmpty()) {
        return front_->data;
    }   
    return -1;
}

int Queue::rear() {
    if (!isEmpty())
        return rear_->data;
    return -1;
}

void Queue::enqueue(int x) {
    if (!isFull()) {
        // if it is first item 
        if (isEmpty()) {
            rear_ = new QueueNodeLL(x);
            front_ = rear_;
        }
        else {
            QueueNodeLL *temp = new QueueNodeLL(x);
            rear_->next = temp;
            rear_ = temp;
        }
        size++;
    }
    else {
        cout << "overflow";
        abort();
    }
}

int Queue::dequeue() {
    if (!isEmpty()) {
        int t = front_->data;
        front_ = front_->next;
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