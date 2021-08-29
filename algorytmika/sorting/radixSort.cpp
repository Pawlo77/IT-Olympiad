int
getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void
countSort(int arr[], int n, int exp_pos) {
    int output[n];
    int occurances[10] = {0};

    for (int i = 0; i < n; i++) {
        occurances[(arr[i] / exp_pos) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        occurances[i] += occurances[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[occurances[(arr[i] / exp_pos) % 10] - 1] = arr[i];
        occurances[(arr[i] / exp_pos) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// n - length of array
void
sort(int arr[], int n) {
    // find the maximum value
    int max = getMax(arr, n);

    // sort for every digit
    for (int exp_pos = 1; max / exp_pos > 0; exp_pos *= 10) {
        countSort(arr, n, exp_pos);
    }
}