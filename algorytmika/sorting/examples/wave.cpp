/*
Given an unsorted array of integers
convert it sucha that arr[0] >= arr[1] <= arr[2] >= arr[3] ...
*/

class Solution{
    private:
    void swap(int *p1, int *p2) {
        int temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr, int n){
        
        for (int i = 0; i < n; i += 2) {
            if (i > 0 && arr[i] < arr[i - 1])
                swap(&arr[i], &arr[i - 1]);
                
            if (i < n - 1 && arr[i] < arr[i + 1])
                swap(&arr[i], &arr[i + 1]);
        }
        
    }
};