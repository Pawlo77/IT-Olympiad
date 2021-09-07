#include <iostream>
using namespace std;

/* Count 1’s in a sorted binary array in decreasing order */

int count(bool arr[], int l, int r) {
    if (l < r) {
        int mid = l + (l + r) / 2;

        if (mid == r || (arr[mid] == 1 && arr[mid + 1] == 0)) {
            return mid + 1;
        }
        
        if (arr[mid] == 1)
            return count(arr, mid + 1, r);
        return count(arr, l, mid - 1);
    }
    return 0;
}

int count_iterative(bool arr[], int n) {
    int l = 0, r = n - 1;

    while (l < r) {
        int mid = l + (l + r) / 2;

        if (mid == r || (arr[mid] == 1 && arr[mid + 1] == 0)) {
            return mid + 1;
        }

        if (arr[mid] == 1)
            l = mid + 1;
        else
            r = mid - 1;
    }
    
    return 0;
}

int main() {
    bool arr[] = {1, 1, 1, 1, 0, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << count_iterative(arr, n) << endl;

    return 0;
}