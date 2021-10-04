#include<iostream>
#include<climits>
using namespace std;

void swap(int *p1, int *p2) {
    auto temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

class MinHeap {
    private:
        int *arr;
        int capacity;
        int heap_size;
    public:
        // constructor
        MinHeap(int x);

        int parent(int x) { return (x - 1)/2; }
        int left(int x) { return (2 * x + 1); }
        int right(int x) { return (2 * x + 2); }

        bool empty() { return heap_size == 0; }
        bool full() { return heap_size == capacity; }

        // to heapify subtree with the root at given index
        void minHeapify(int x);

        // to extract root which is minimum element
        int extractMin();

        // decreases key value of key at index x to new_val
        void decreaseKey(int x, int new_val);

        // returns the minimum key (at root)
        int getMin();

        // deletes a key stored at index x 
        void deleteKey(int x);

        // inserts a new key x
        void insertKey(int x);
};

MinHeap::MinHeap(int x) { 
    heap_size = 0;
    capacity = x;
    arr = new int[capacity];
}

void MinHeap::insertKey(int x) { 
    if (!full) { 
        arr[heap_size++] = x;

        // fix the min heap property
        int i = heap_size - 1;
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
}

void MinHeap::decreaseKey(int x, int new_val) {
    arr[x] = new_val;

    while (x != 0 && arr[parent(x)] > arr[x]) {
        swap(&arr[x], &arr[parent(x)]);
        x = parent(x);
    }
}

int MinHeap::extractMin() {
    if (!empty()) {
        if (heap_size == 1) {
            heap_size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[heap_size - 1];
        MinHeapify(0);

        return root;
    }
    return INT_MAX;
}

void MinHeap::deleteKey(int x) { 
    decreaseKey(x, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int x) {
    int l = left(x);
    int r = right(x);
    int smallest = x;

    if (l < heap_size && arr[l] < arr[smallest])
        smallest = l;
    if (r < heap_size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != x) {
        swap (&arr[x], &arr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::getMin() {
    if (!empty()) {
        return arr[0];
    }
    return INT_MAX;
}