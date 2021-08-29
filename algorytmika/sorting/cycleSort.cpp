void
swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// n - length of array
void
sort(int arr[], int n) {
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];
        int pos = cycle_start;

        // find where to put the item
        for (int i = pos + 1; i < n; i++) {
            if (arr[i] < arr[cycle_start]) {
                pos++;
            }
        }
        
        // if item is already in correct position
        if (pos == cycle_start) {
            continue;
        }

        // ignore dublicates
        while (item == arr[pos]) {
            pos += 1;
        }

        // put item to its correct position
        if (pos != cycle_start) {
            swap(&item, &arr[pos]);
        }

        // rotate rest of the cyrcle
        while (pos != cycle_start) {
            pos = cycle_start;

            // Find position where we put the element
            for (int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos += 1;
 
            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;
 
            // put the item to it's right position
            if (item != arr[pos]) {
                swap(&item, &arr[pos]);
            }
        }
    }
}