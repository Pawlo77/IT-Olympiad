int
BinarySearch(int arr[], int k, int start, int end) {
    int middle;

    while (start <= end) {
        middle = (start + end) / 2;

        if (arr[middle] == k) {
            return middle + 1;
        }

        if (arr[middle] > k) {
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }
    }

    return (k > arr[start]) ? start + 1 : start;
}

// n - length of array
void
binary_insertion_sort(int arr[], int n) {
    int j, key, loc;
    for (int i = 1; i < n; i++) {
        j = i - 1;
        key = arr[i];

        // find location where selected key should be inserted
        loc = BinarySearch(arr, key, 0, j);

        // move all elements after that location to create space
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// n - length of array
void
sort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // move all elements after that location to create space
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}