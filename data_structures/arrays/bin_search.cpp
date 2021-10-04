/* binary search implementation
for sorted rotated 2D array */

int search(int A[], int l, int r, int key){
    if (l > r)
        return -1;
    
    int mid = l + (r - l) / 2;
    if (A[mid] == key) return mid;
    
    // if left part is sorted
    if (A[l] <= A[mid]) {   
        // if it is in sorted part, recurr for it
        if (A[l] <= key && key <= A[mid])
            return search(A, l, mid - 1, key);
        // else check the unsorted one
        return search(A, mid + 1, r, key);
    }
    // otherwise right part must be sorted
    else {
        // if it is in sorted part, recurr for it
        if (A[mid] <= key && key <= A[r])
            return search(A, mid + 1, r, key);
        // else check the unsorted one
        return search(A, l, mid - 1, key);
    }
}