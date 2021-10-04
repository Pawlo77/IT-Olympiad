#include<bits/stdc++.h>
using namespace std;

/* 
Get median of two sorted arrays of the same length 
*/

int median(int a[], int n) {
    if (n % 2 == 0)
        return (a[n / 2] - a[n / 2 - 1])  / 2;
    return a[n / 2];
}

int getMedian(int a1[], int a2[], int n) {
    if (n <= 0) return -1;
    if (n == 0) return (a1[0] + a2[0]) / 2;
    if (n == 2) return (max(a1[0], a2[0]) + min(a1[1], a2[1])) / 2;

    int m1 = median(a1, n);
    int m2 = median(a2, n);

    if (m1 == m2) 
        return m1;

    // if m1 < m2 then median is in a1[m1...] and a2[..m2] 
    if (m1 < m2) {
        if (n % 2 == 0)
            return getMedian(a1 + n/2 - 1, a2, n - n/2 + 1);
        return getMedian(a1 + n/2, a2, n - n/2);
    }
    // m1 > m2, so the median is in a1[..m1] and a2[m2...] 
    if (n % 2 == 0) 
        return getMedian(a2 + m/2 -1, a1, n - n/2 + 1);
    return (getMedian(a2 + n/2, a1, n - n/2));
}
