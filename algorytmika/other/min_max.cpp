#include <iostream>
#include <climits>
using namespace std;

/*
find the minimum number of swaps required so that the 
maximum element is at the beginning and the minimum 
element is at last with the condition that only swapping 
of adjacent elements is allowed
*/

int min_max(int arr[], int n) {
    // get pos of max and min val in the arr
    int min = 0, max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= arr[min]) min = i; // rightmost index
        if (arr[i] > arr[max]) max = i; // leftmost index
    }

    if (max < min) 
        return max + (n - min - 1); 
    else if (max > min) 
        return max + (n - min - 2);
    else 
        // max = min and there occur only one,
        // which makes operation unpossible
        return -1;
}

int main() {
    int arr[] = {3, 1, 5, 3, 5, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << min_max(arr, n) << endl;

    return 0;
}