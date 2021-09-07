#include <iostream>
#include <vector>
using namespace std;

/* Given an array which is sorted, but after sorting 
some elements are moved - arr[i] may be present 
at arr[i+1] or arr[i-1]. */

int binSearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (x == arr[mid]) 
            return mid;
        else if (x == arr[mid + 1])
            return mid + 1;
        else if (x == arr[mid - 1])
            return mid - 1;

        if (arr[mid] > x)
            return binSearch(arr, l, mid - 1, x);
        else 
            return binSearch(arr, mid + 1, r, x);

    }
    return -1;
}

int main() {
    int arr[] = {3, 2, 10, 4, 40};
    int n = 5;
    int x = 4;

    int result = binSearch(arr, 0, n - 1, x);

    cout << result << endl;
    
    return 0;
}