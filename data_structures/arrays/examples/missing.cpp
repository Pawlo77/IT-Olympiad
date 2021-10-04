/* missing number in an array
given array of size n - 1 with numbers from 
range 1 to n (each one exacly once). Find the missing number
*/

// solution 1 - requires additional space 
int MissingNumber(vector<int>& arr, int n) {
    vector<bool> present(n, 0);
    
    for (int i = 0; i < n - 1; i++)
        present[arr[i] - 1] = 1;
        
    for (int i = 0; i < n; i++)
        if (!present[i])
            return i + 1;
}

/* solution 2 
1. initial sum = 1; c = 2;
2. for every element in an array
    sum -= arr[i] + c
    c++
3. return sum
*/

int MissingNumber(vector<int>& arr, int n) {
    int sum = 1, c = 2;
    for (int i = 0; i < n - 1; i++) {
        sum = sum - arr[i] + c;
        c++;
    }
    return sum;
}