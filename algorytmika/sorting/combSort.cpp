void
swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int 
gatNextGap(int gap) {
    gap = (gap * 10) / 13;

    if (gap < 1) {
        return 1;
    }
    return gap;
}

// n - length of array
void
sort(int arr[], int n) {
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped) {
        // find the next gap
        gap = gatNextGap(gap);

        // set swapped as false to check weather swap occured in this iteration
        swapped = false;

        // compare all elements with current gap
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                swapped = true;
            }
        }
    }
}