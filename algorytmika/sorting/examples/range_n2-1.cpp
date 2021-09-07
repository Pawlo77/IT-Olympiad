#include <iostream>
#include <vector>
using namespace std;

/* Sort n numbers in range from 0 to n^2 – 1 
in linear time */

/* for range 1 to n^2 subtract 1 from every
digit and than after sorting add 1 */

/* for range 0 to n^3-1 call countSort 3 times */

class Solution
{
    private:
    void countSort(int arr[], int n, int pos) {
        int output[n]; 

        int p, i;

        // prepare occurances array
        int occurances[n];        
        for (i = 0; i < n; i++) {
          occurances[i] = 0;
        }

        // count occurances
        for (i = 0; i < n; i++) {
            occurances[(arr[i] / pos) % n]++;
        }
        for (i = 1; i < n; i++) {
            occurances[i] += occurances[i - 1];
        }

        // build the output array
        for (i = n - 1; i >= 0; i--) {
            p = (arr[i] / pos) % n;
            output[occurances[p] - 1] = arr[i]; // indexing starts from 0
            occurances[p]--;
        }

        // copy the output array into original array
        for (i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    public:
    void sort(int arr[], int n)
    {
        // Radix sort implementation

        // scince our range is 0-n^2 - 1,
        // we can call count sort twice (for exp_pos 1 and n)
        // -- we treat numbers as numbers with numerical basis n
        countSort(arr, n, 1);
        countSort(arr, n, n);
    }
};

int main() {

    int n = 5;
    int arr[] = {24, 12, 0, 15, 8};

    Solution ob;
    ob.sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}