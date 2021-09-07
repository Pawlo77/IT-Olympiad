#include <iostream>
#include <vector>
#include <set>
using namespace std;

/* Write function returns k'th smallest element in 
arr[l..r] ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT */

/* all below can be reversed to max and min respectively */

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int l, int r) {
    int x = arr[r];
    int i = l;

    for (int j = l; j < r; j++)
        if (arr[j] <= x)
            swap(&arr[i++], &arr[j]);

    swap(&arr[i], &arr[r]);
    return i;
}

int randomPartition(int arr[], int l, int r) {
    int range = r - l + 1;
    int pivot = rand() % range;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
}

int medianPartition(int arr[], int l, int r, int m) {    
    // search for m in arr 
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == m)
            break;
    swap(&arr[i], &arr[r]);

    return partition(arr, l, r);
}

void merge(int *arr, int m, int n) {
    // create temporary subarrays
    auto const l_arr_length = m;
    auto const r_arr_length = n - m;
    auto *l_arr = new int[l_arr_length];
    auto *r_arr = new int[r_arr_length];

    // populate both temp arrays
    for (auto i = 0; i < l_arr_length; i++) {
        l_arr[i] = *(arr + i);
    }
    for (auto i = 0; i < r_arr_length; i++) {
        r_arr[i] = *(arr + m + i);
    }

    // merge temp arrays
    auto l_idx = 0, r_idx = 0, arr_idx = 0;
    while (l_idx < l_arr_length && r_idx < r_arr_length) {
        if (l_arr[l_idx] <= r_arr[r_idx]) {
            // if smallest val from left arr is smaller from
            // smallest val from right arr then take it
            *(arr + arr_idx) = l_arr[l_idx];
            l_idx++;
        }
        else {
            // take one from right arr
            *(arr + arr_idx) = r_arr[r_idx];
            r_idx++;
        }
        arr_idx++;
    }

    // populate arr with remainings of r_arr and l_arr
    while (l_idx < l_arr_length) {
        *(arr + arr_idx) = l_arr[l_idx];
        l_idx++;
        arr_idx++;
    }
    while (r_idx < r_arr_length) {
        *(arr + arr_idx) = r_arr[r_idx];
        r_idx++;
        arr_idx++;
    }
};

void sort(int *arr, int n) {
    if (n <= 1) {
        return;
    }

    int m = n / 2;
    sort(arr, m);     // left subarray
    sort(arr + m, n - m); // right subarray
    merge(arr, m, n);
}

int findMedian(int *arr, int n) {
    sort(arr, n);
    return arr[n/2];
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

// average - O(n), worst - O(n^2)
int kthSmallestQuick(int arr[], int l, int r, int k) {
    // if k is smaller than number of elements in arr
    if (k > 0 && k <= r - l + 1) {
        int pos = partition(arr, l, r);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallestQuick(arr, l, pos - 1, k);
        return kthSmallestQuick(arr, pos + 1, r, k - pos + l - 1);
    }
    return -1;
}

// average - O(n), worst - O(n^2), less likely to occurr
int kthSmallestQuickRandomized(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int pos = randomPartition(arr, l, r);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallestQuickRandomized(arr, l, pos - 1, k);
        return kthSmallestQuickRandomized(arr, pos + 1, r, k - pos + l - 1);
    }
    return -1;
}

// average - O(log n), worst - O(n)
int kthSmallestSet(int arr[], int n, int k) {
    set<int> s(arr, arr + n);
    set<int>::iterator itr = s.begin();
    advance(itr, k - 1); // advance itr to point to kth element
    return *itr;
}

// O(n + k log n) 
int kthSmallestHeap(int arr[], int n, int k) {
    MinHeap MH(arr, n);

    for (int i = 0; i < k - 1; i++)
        MH.ExtractMin();

    return MH.getMin();
}

// O(n)
int kthsmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int i;
        int n = r - l + 1;
        int n_grups = (n+4)/5;
        int median[n_grups];

        for (i=0; i < n_grups - 1; i++) 
            median[i] = findMedian(arr + l + i * 5, 5);

        // last grup may not be fully filled
        if (n % 5 == 0)
            median[i++] = findMedian(arr + l + i * 5, 5);
        else
            median[i++] = findMedian(arr + l + i * 5, n % 5);

        // find median of all medians using recursive call
        int MedOfMed = i == 1 ? median[i-1]: kthsmallest(median, 0, i-1, i/2);
        // partition around a random element
        int pos = medianPartition(arr, l, r, MedOfMed);

        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left
            return kthsmallest(arr, l, pos-1, k);
    
        // Else recur for right subarray
        return kthsmallest(arr, pos+1, r, k-pos+l-1);
    }
    return - 1;
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    int result = kthsmallest(arr, 0, n-1, k);
    cout << result << endl;
    
    return 0;
}