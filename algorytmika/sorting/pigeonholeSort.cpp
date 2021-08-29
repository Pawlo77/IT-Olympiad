void
getMaxMin(int arr[], int n, int *min, int *max) {
    *max = *min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        else if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

// n - length of array
void
sort(int arr[], int n) {
    int min, max;
    getMaxMin(arr, n, &min, &max);
    int range = max - min + 1;

    vector<int> holes[range];
    for (int i = 0; i < n; i++) {
        holes[arr[i] - min].push_back(arr[i]);
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        for (vector<int>::iterator it = holes[i].begin(); it != holes[i].end(); ++it) {
            arr[index++] = *it;
        }
    }
}