/* 
Given an array of positive numbers, find the maximum 
sum of a subsequence with the constraint that no 
2 numbers in the sequence should be adjacent in the array
*/

int FindMaxSum(int arr[], int n) {
    int maxE = 0, maxI = arr[0], t;
    for (int i = 1; i < n; i++) {
        t = max(maxE, maxI);
        maxI = maxE + arr[i];
        maxE = t;
    }
    return max(maxE, maxI);
}