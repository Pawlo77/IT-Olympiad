void
insertion_sort(vector<float> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j - 1] < arr[j]) {
                break;
            }
            swap(arr[j], arr[j - 1]);
        }
    }
}

void
getMaxMin(float arr[], int n, float *min, float *max) {
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

// sort float numbers in range (0.0, 1.0)
// n - length of array
void
sort(float arr[], int n) {
    // create empty buckets
    vector<float> buckets[n];

    // put array elements into buckets
    for (int i = 0; i < n; i++) {
        int pos = n * arr[i];
        buckets[pos].push_back(arr[i]);
    }

    // sort each bucket and merge it back into arr
    int index = 0;
    for (int i = 0; i < n; i++) {
        insertion_sort(buckets[i]);

        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

void
sort_vector(vector<float> &arr) {
    int n = arr.size();

    // create empty buckets
    vector<float> buckets[n];

    // put array elements into buckets
    for (int i = 0; i < n; i++) {
        int pos = n * arr[i];
        buckets[pos].push_back(arr[i]);
    }

    arr.clear();

    // sort each bucket and merge it back into arr
    int index = 0;
    for (int i = 0; i < n; i++) {
        insertion_sort(buckets[i]);

        for (int j = 0; j < buckets[i].size(); j++) {
            arr.push_back(buckets[i][j]);
        }
    }
}

// sort float numbers in any positive range (>0.0)
// n - length of array
void
sort_all(float arr[], int n) {
    // calculate range of each bucket
    float min, max;
    getMaxMin(arr, n, &min, &max);
    float range = (max - min) / n;

    // create empty buckets
    vector<float> buckets[n];

    // put array elements into buckets
    for (int i = 0; i < n; i++) {
        int pos = (arr[i] - min) / range;
        buckets[pos].push_back(arr[i]);
    }

    // sort each bucket and merge it back into arr
    int index = 0;
    for (int i = 0; i < n; i++) {
        insertion_sort(buckets[i]);

        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// sort float numbers in range (-1.0, 1.0) (use sort for any range)
// n - length of array
void
sort_mixed(float arr[], int n) {
    // create 2 vectors for positive and negative numbers
    vector<float> positive, negative;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            positive.push_back(arr[i]);
        }
        else {
            negative.push_back(-1 * arr[i]);
        }
    }

    sort_vector(positive);
    sort_vector(negative);

    // merge negative and positive numbers
    for (int i = 0; i < negative.size(); i++) {
        arr[i] = -1 * negative[negative.size() - 1 - i];
    }
    for (int i = negative.size(); i < n; i++) {
        arr[i] = positive[i - negative.size()];
    }
}