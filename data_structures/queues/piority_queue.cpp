#include <iostream>
#include <queue>
#include <climits>

using namespace std;

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

class MaxHeap {
    private:
        int *arr;
        int capacity;
        int size;
    public:
        MaxHeap(int x) {
            capacity = x;
            arr = new int[capacity];
            size = 0;
        }

        int parent(int i) { return (i - 1) / 2; }
        int left(int i) { return 2 * i + 1; }
        int right(int i) { return 2 * i + 2; }

        bool isEmpty() { return size == 0; }
        bool isFull() { return capacity == size; }

        // heapify a subtree with a root at index i
        void heapify(int i);
        // decreases key value of key at index i to val
        void decreeaseKey(int i, int val);
        // to extract root - maximum value
        int extractMax();
        // returns the maximum key - key at root
        int getMax();
        // deletes a key stored at index i
        void deleteKey(int i);
        // inserts a new key i
        void insertKey(int i);
        // to fix max heap property (from key at index i)
        void fix(int i);
};

void MaxHeap::fix(int i) {
    while (i != 0 && arr[parent(i)] < arr[i]) {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::insertKey(int i) {
    if (!isFull()) {
        // insert new key at the end
        int j = size;
        arr[size++] = i;
        fix(j);
    }
    else {
        cout << "overflow" << endl;
        abort();
    }
}

void MaxHeap::decreeaseKey(int i, int val) {
    if (!isEmpty() && i < size) {
        arr[i] = val;
        fix(i);
    }
    cout << "out of range" << endl;
    abort();
}

void MaxHeap::deleteKey(int i) {
    decreeaseKey(i, INT_MAX);
    extractMax();
}

void MaxHeap::heapify(int i) { 
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < size && arr[l] > arr[i])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i) { 
        swap(&arr[i], &arr[largest]);
        heapify(largest);
    }
}

int MaxHeap::extractMax() {
    if (!isEmpty()) {
        if (size == 1)
            return arr[--size];

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return root;
    }
    cout << "underflow" << endl;
    abort();
}

int MaxHeap::getMax() {
    if (!isEmpty())
        return arr[0];
    cout << "heap is empty" << endl;
    return INT_MIN;
}

int main() { 
    // Here is max heap priority_queue implementation
    MaxHeap *q = new MaxHeap(100);
    
    q->insertKey(10);
    q->insertKey(30);
    q->insertKey(20);
    q->insertKey(5);
    q->insertKey(1);

    cout << q->getMax() << endl;
    q->extractMax();
    cout << q->getMax() << endl;

    return 0;
}

// int main() {
//     //  Here is c++ STL implementation:
//     priority_queue<int> q;

//     q.push(10);
//     q.push(30);
//     q.push(20);
//     q.push(5);
//     q.push(1);

//     cout << q.top() << endl;
//     q.pop();
//     cout << q.top() << endl;

//     return 0;
// }