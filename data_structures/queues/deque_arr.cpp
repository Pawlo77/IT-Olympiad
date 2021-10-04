#include <iostream>

using namespace std;

class Deque {
    private:
        int capacity;
        int size;
        int front, rear;
        int *arr;
    public:
        Deque(int x) {
            capacity = x;
            size = front = rear = 0;
            arr = new int[capacity];
        }

        bool isEmpty() { return size == 0; }
        bool isFull() { return size == capacity; }

        // adds x to the front of deque
        void insertFront(int x);
        // adds x to the rear of deque
        void insertRear(int x);
        // deletes an item from front of deque
        void deleteFront();
        // deletes an item from rear of deque
        void deleteRear();
        // returns front key of deque
        int getFront();
        // returns rear key of deque
        int getRear();

        void print();
};

void Deque::insertFront(int x) { 
    if (!isFull()) {
        if (isEmpty())
            front = rear = 0;
        else 
            front = front == 0 ? capacity - 1 : front - 1;
        arr[front] = x;
        size++;
    }
    else {
        cout << "overflow" << endl;
        abort();
    }
}

void Deque::insertRear(int x) {
    if (!isFull()) {
        if (isEmpty()) 
            front = rear = 0;
        else 
            rear = rear == capacity - 1 ? 0: rear + 1;
        arr[rear] = x;
        size++;
    }
    else {
        cout << "overflow" << endl;
        abort();
    }
}

void Deque::deleteFront() {
    if (!isEmpty()) {
        front = front == capacity - 1 ? 0 : front + 1;
        size--;
    }
    else {
        cout << "underflow" << endl;
        abort();
    }
}

void Deque::deleteRear() {
    if (!isEmpty()) {
        rear = rear == 0 ? capacity - 1 : rear - 1;
        size--;
    }
    else {
        cout << "underflow" << endl;
        abort();
    }
}

int Deque::getFront() {
    if (!isEmpty())
        return arr[front];
    cout << "underflow" << endl;
    abort();
}

int Deque::getRear() {
    if (!isEmpty())
        return arr[rear];
    cout << "underflow" << endl;
    abort();
}

void Deque::print() {
    if (!isEmpty()) {
        for (int i = 0; i < capacity; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main() {
    Deque dq(4);

    dq.insertRear(5);
    dq.insertRear(10);
    dq.insertFront(1);
    dq.print();

    cout << dq.getRear() << endl;
    dq.deleteRear();
    cout << dq.getRear() << endl;
    dq.deleteRear();
    cout << dq.getRear() << endl;

    return 0;
}