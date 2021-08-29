#define RANGE 255

void
sort_char(char arr[]) {
    int output[strlen(arr)];
    int occurances[RANGE + 1] = {0};

    // count occurances of every possible sign
    for (int i = 0; arr[i]; i++) {
        occurances[arr[i]]++;
    }

    for (int i = 1; i <= RANGE; i++) {
        occurances[i] += occurances[i - 1];
    }

    // build the output array
    for (int i = 0; arr[i]; i++) {
        output[occurances[arr[i]] - 1] = arr[i];
        occurances[arr[i]]--;
    }

    // copy result to original array
    for (int i = 0; arr[i]; i++) {
        arr[i] = output[i];
    }
}

void
sort_int(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> occurances(range), output(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        occurances[arr[i] - min]++;
    }

    for (int i = 1; i < occurances.size(); i++) {
        occurances[i] += occurances[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[occurances[arr[i] - min] - 1] = arr[i];
        occurances[arr[i] - min]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}