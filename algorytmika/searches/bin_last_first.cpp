/* find first or last occurance of given value 
in sorted array using binary search */

int first(int arr[], int n, int x) {
    int s = 0, e = n - 1;
    int r = -1, mid;
    
    while (s <= e) {
        mid = s + (e - s) / 2;
        
        if (arr[mid] == x) {
            r = mid;
            e = mid - 1;
        }
        else if (arr[mid] < x)
            s = mid + 1;
        else 
            e = mid - 1;
    }
    
    return r;
}

int last(int arr[], int n, int x) {
    int s = 0, e = n - 1;
    int r = -1, mid;
    
    while (s <= e) {
        mid = s + (e - s) / 2;
        
        if (arr[mid] == x) {
            r = mid;
            s = mid + 1;
        }
        else if (arr[mid] < x)
            s = mid + 1;
        else 
            e = mid - 1;
    }
    
    return r;
}