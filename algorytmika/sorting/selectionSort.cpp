void
swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int
select(int arr[], int i) {
    for (int j = i; j >= 0; j--) {
        if (arr[j] > arr[i]) {
            i = j;
        }
    }
    return i;
}

// sort from right to left
// n - length of array
void
sort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[i], &arr[select(arr, i)]);
    }
}
