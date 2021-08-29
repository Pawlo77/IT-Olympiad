void
merge(int arr[], int l, int m, int r) {
    // create temporary subarrays
    auto const l_arr_length = m - l + 1; // take the m as well
    auto const r_arr_length = r - m;
    auto *l_arr = new int[l_arr_length];
    auto *r_arr = new int[r_arr_length];

    // populate both temp arrays
    for (auto i = 0; i < l_arr_length; i++) {
        l_arr[i] = arr[l + i];
    }
    for (auto i = 0; i < r_arr_length; i++) {
        r_arr[i] = arr[m + i + 1];
    }

    // merge temp arrays
    auto l_idx = 0, r_idx = 0;
    int arr_idx = l;
    while (l_idx < l_arr_length && r_idx < r_arr_length) {
        if (l_arr[l_idx] <= r_arr[r_idx]) {
            // if smallest val from left arr is smaller from
            // smallest val from right arr then take it
            arr[arr_idx] = l_arr[l_idx];
            l_idx++;
        }
        else {
            // take one from right arr
            arr[arr_idx] = r_arr[r_idx];
            r_idx++;
        }
        arr_idx++;
    }

    // populate arr with remainings of r_arr and l_arr
    while (l_idx < l_arr_length) {
        arr[arr_idx] = l_arr[l_idx];
        l_idx++;
        arr_idx++;
    }
    while (r_idx < r_arr_length) {
        arr[arr_idx] = r_arr[r_idx];
        r_idx++;
        arr_idx++;
    }
};


// l - starting index, r - ending index
void
sort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }

    int m = (l + r) / 2;
    sort(arr, l, m);     // left subarray
    sort(arr, m + 1, r); // right subarray
    merge(arr, l, m, r);
}
