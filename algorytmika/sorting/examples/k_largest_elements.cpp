#include <iostream>
#include <vector>
#include <set>
using namespace std;

/* Write function returns k smallest elements in 
arr[l..r] ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT */

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

class MinHeap {
    int *arr;
    int heap_size;

    public:
    int getMin() {return arr[0];}

    void print() {
        for (int i = 0; i < heap_size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void MinHeapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < heap_size && arr[l] < arr[smallest])
            smallest = l;
        if (r < heap_size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i) {
            swap(&arr[smallest], &arr[i]);
            MinHeapify(smallest);
        }
    }

    int ExtractMin() {
        if (heap_size == 0) {
            return -1;
        }
        int root = arr[0];

        if (heap_size > 1) {
            arr[0] = arr[heap_size - 1];
            MinHeapify(0);
        }
        heap_size--;

        return root;
    }

    MinHeap(int a[], int n) {
        heap_size = n;
        arr = a;

        int i = (heap_size - 1) / 2;
        while (i >= 0)
            MinHeapify(i--);
    }
};

int partition(int arr[], int l, int r) {
    int p = arr[r], i = l;

    for (int j = l; j <= r; j++) 
        if (arr[j] > p) 
            swap(&arr[i++], &arr[j]);

    swap(&arr[r], &arr[i]);
    return i;
}

void sort(int arr[], int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        sort(arr, l, p-1);
        sort(arr, p+1, r);
    }
}

void kLargest(int arr[], int n, int k)
    {
        // build heap from first k elements
        MinHeap *MH = new MinHeap(arr, k);

        for (int i = k; i < n; i++)
            if (arr[0] < arr[i]) {
                arr[0] = arr[i];
                MH->MinHeapify(0);
            }
        // now k largest elements are on the begining of the arr

        // sort them
        sort(arr, 0, k - 1);
    }

int main() {
    int arr[] = { 7, 10, 4, 20, 15, 21,31,12};
    int n = sizeof(arr) / sizeof(arr[0]), k = 4;
    kLargest(arr, n, k);

    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}