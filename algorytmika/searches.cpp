#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int LinearSearch(int arr[], int n, int k) {
	for (int i=0; i < n; i++) {
	    if (arr[i] == k) {
	        return i + 1;
	    }
	}
	return -1;
}

int BinarySearch(int arr[], int n, int k) {
    int middle, start = 0, end = n - 1;
        
    while (start <= end) {
        middle = (start + end) / 2;

        /**
         Note that for large values of start and end, 
         exceeding int range it fails. Possible solutions:
         - middle = low + ((high - low) / 2)
         - FASTER: middle = ((usigned int) low + (usigned int) high) >> 1
         */
            
        if (arr[middle] == k) {
            return middle + 1;
        }
        
        if (arr[middle] > k) {
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }
    }
    return -1;   
}

int JumpSearch(int arr[], int n, int k) {
    int step = sqrt(n), increase = step;

    // find the block where element is present (if is)
    int previous = 0;
    while (arr[min(step, n) - 1] < k){
        previous = step;
        step += increase;
        if (previous >= n) { // out of range
            return -1;
        }
    }

    // perform linearSearch on that block
    while (arr[previous] < k){
        previous++;

        if (previous == min(step, n)) { // out of range
            return -1;
        }
    }

    return (arr[previous] == k) ? previous + 1 : -1;
}

int InterpolationSearch(int arr[], int n, int k) {
    int start = 0, end = n - 1;

    while ( start <= end && arr[start] <= k <= arr[end]) {
        if (start == end) {
            return arr[start] == k ? start + 1: -1;
        }

        // probing the position with keeping uniform distribution in mind
        int pos = start + (k - arr[start]) * (end - start) / (arr[end] - arr[start]);

        if (arr[pos] == k) {
            return pos + 1;
        }
        
        if (arr[pos] < k) {
            start = pos + 1;
        }
        else {
            end = pos - 1;
        }
    }
    return -1;    
}

int ExponentialSearch (int arr[], int n, int k) {
    if (arr[0] == k){
        return 1;
    }

    // find range for binary search by repeated doubling
    int i = 1;
    while (i < n && arr[i] <= k){
        i *= 2;
    }

    // perform binary search on range i/2 - i
    int middle, start = i / 2, end = min(i, n - 1);

    while (start <= end) {
        middle = (start + end) / 2;
            
        if (arr[middle] == k) {
            return middle + 1;
        }
        
        if (arr[middle] > k) {
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }
    }
    return -1;   
}

int TernarySearch (int arr[], int n, int k) {
    int middle1, middle2, start = 0, end = n - 1;
        
    while (start <= end) {
        middle1 = start + (end - start) / 3;
        middle2 = middle1 + (end - start) / 3;
            
        if (arr[middle1] == k) {
            return middle1 + 1;
        }
        if (arr[middle2] == k) {
            return middle2 + 1;
        }
        
        if (arr[middle1] > k) {
            end = middle1 - 1;
        }
        else if (arr[middle2] < k) {
            start = middle2 + 1;
        }
        else {
            start = middle1 + 1;
            end = middle2 - 1;
        }
    }
    return -1;   
}
