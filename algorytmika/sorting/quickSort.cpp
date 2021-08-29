void
swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// n - length of array
// insertion sort to sort median arr
void
sort_median(int arr[], int n) {
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

int
partition(int arr[], int l, int r) {
    // option for pivot lowering the chances of worst case
    // - pivot being median of 1st, last and middle element of arr
    // int middle = (l + r) / 2;
    // int pivot = arr[middle]; 
    // int median_arr[3] = {arr[l], arr[r], arr[middle]};
    // sort_median(median_arr, 3);
    // int pivot = median_arr[1];

    int pivot = arr[r];
    int i = l - 1; // Index of smaller element

    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

// optimized quick sort
void
quickSortInteractive(int arr[], int l, int r) {
    int stack[r - l + 1];
    int top = -1;

    // push back values of r and l to the stack
    stack[++top] = l;
    stack[++top] = r;

    // keep popping from stack until its empty
    while (top >= 0) {
        r = stack[top--];
        l = stack[top--];

        int p = partition(arr, l, r);

        // if there are elements on the left side of the p
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // same for elements on the right side of the p
        if (p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
    }
}

// l - starting index, r - ending index
void
sort(int arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);

        sort(arr, l, pi - 1);
        sort(arr, pi + 1, r);
    }
}
