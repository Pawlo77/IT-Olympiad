/* largest sym contiguous subarray */
long long maxSubarraySum(int arr[], int n){       
    long long maxSoFar = INT_MIN;
    long long maxHere = 0;
    
    for (int i = 0; i < n; i++) {
        maxHere += arr[i];
        if (maxSoFar < maxHere) maxSoFar = maxHere;
        if (maxHere < 0) maxHere = 0;
    }
    
    return maxSoFar;
}

// this one handles when all elements in 
// array are negative
int maxSubArraySum(int a[], int size) {
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

// option that prints found subarray
int maxSubArraySum(int a[], int size) {
    int max_so_far = INT_MIN, max_ending_here = 0,
       start =0, end = 0, s=0;
 
    for (int i=0; i< size; i++ )
    {
        max_ending_here += a[i];
 
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
 
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is "
        << max_so_far << endl;
    cout << "Starting index "<< start
        << endl << "Ending index "<< end << endl;
}