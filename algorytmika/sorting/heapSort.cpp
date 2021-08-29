void
swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Heapify function to maintain heap property.
void
heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // if left is part of the heap and
    // is greater than its parrent
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // if we found new largest node
    if (i != largest) {
        swap(&arr[largest], &arr[i]);

        // recurrently call itself again for changed child
        heapify(arr, n, largest);
    }
}

// Function to build a Heap from array.
void
buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}


// n - length of array
void
sort(int arr[], int n) {
    buildHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        // replace fist node and last node
        swap(&arr[i], &arr[0]);

        // maintan max-heap
        heapify(arr, i, 0);
    }
}