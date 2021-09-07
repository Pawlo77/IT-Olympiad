#include <iostream>
#include <climits>
using namespace std;

/* Find the closest pair from two sorted arrays
ASSUMPTION: the pair has an element from each array */

void find(int arr1[], int arr2[], int n1, int n2, int sum) {
    int diff = INT_MAX;

    int l = 0,  r = n2 - 1;
    int p1, p2;
    while (l < n1 && r >= 0) {
        int c = abs(arr1[l] + arr2[r] - sum);
        if (c < diff) {
            diff = c;
            p1 = arr1[l];
            p2 = arr2[r];
        }
        if (arr1[l] + arr2[r] < sum) l++; else r--;
    }
    cout << p1 << " " << p2 << endl;
}

void find_in_one(int arr[], int n, int x) {
    int p1, p2, diff = INT_MAX;

    int l = 0, r = n - 1;
    while (l < r) {
        int c = abs(x - arr[l] - arr[r]);
        if (c < diff) {
            p1 = arr[l];
            p2 = arr[r];
            diff = c;
        }

        if (arr[l] + arr[r] < x) 
            l++;
        else 
            r--;
    }

    cout << p1 << " " << p2 << endl;
}

int main() {
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    int x = 38;

    find(ar1, ar2, m, n, x);

    return 0;
}