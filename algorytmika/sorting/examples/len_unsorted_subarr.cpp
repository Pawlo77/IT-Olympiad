/*
Given an unsorted array Arr of size N.
Find the subarray Arr[s...e] such that sorting this subarray makes the whole array sorted.
If no such subarray exists, return {0, 0}.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int>
printUnsorted(int arr[], int n) {
    int s, e, min, max;

    for (s = 0; s < n - 1; s++)
        if (arr[s] > arr[s + 1])
            break;

    if (s == n - 1)
        // array is sorted
        return {0, 0};

    for (e = n - 1; e > 0; e--)
        if (arr[e - 1] > arr[e])
            break;

    min = arr[s];
    max = min;
    for (int i = s; i <= e; i++) {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }

    for (int i = 0; i < s; i++)
        if (arr[i] > min) {
            s = i;
            break;
        }
    for (int i = n - 1; i >= e + 1; i--)
        if (arr[i] < max) {
            e = i;
            break;
        }

    return {s, e};
}

int
main() {
    int n = 9;
    int arr[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
    auto ans = printUnsorted(arr, n);
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}