/*
how far (or close) the array is from being sorted. 
If the array is already sorted, then the inversion 
count is 0, but if the array is sorted in the reverse order, 
the inversion count is the maximum. 
*/

long long merge(long long arr[],
                long long temp[],
                long long l,
                long long m,
                long long r) {
    long long count = 0;
    // index for left subarr, right subarr, merged arr
    long long i = l, j = m, k = l;
    
    while (i <= m - 1 && j <= r) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else { 
            temp[k++] = arr[j++];
            count += m - i;
        }    
    }
    
    while (i <= m - 1) 
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
        
    for (long long i = l; i <= r; i++)
        arr[i] = temp[i];
    
    return count;
}
long long mergeSort(long long arr[],
                    long long temp[],
                    long long l,
                    long long r) {
    long long count = 0;
    if (l < r) {
        long long m;
        m = l + (r - l) / 2;
        count += mergeSort(arr, temp, l, m);
        count += mergeSort(arr, temp, m + 1, r);
        
        count += merge(arr, temp, l, m + 1, r);
    }
    return count;
}
// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long inversionCount(long long arr[], long long N)
{
    long long temp[N];
    return mergeSort(arr, temp, 0, N - 1);
}