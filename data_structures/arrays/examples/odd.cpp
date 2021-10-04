/* 
Given an array of positive integers. All numbers occur
an even number of times except one number which occurs
an odd number of times.
*/

/* solution
run XOR for every node
(XOR of 2 simmilar nodes is 0; XOR of 0 and x is x)
*/

int getOddOccurrence(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++)
        res = res ^ arr[i];
        
    return res;
}