#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#include "quickSort.cpp"

// UTILITY FUNCTIONS
// Function to print an array
void
printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void
printArrayV(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver code
int
main() {
    int arr[] = {1, 1, 1, 37, 23, 0, 17, 12, 31, 46, 12, 32, 14};
    // vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10};
    // char arr2[] = "geeksforgeeks";
    float arr3[] = {-0.897, 0.565, 0.656,
                   -0.1234, 0, 0.3434};
    
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    // printArrayV(arr);
    printArray(arr, arr_size);

    quickSortInteractive(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    // printArrayV(arr);
    printArray(arr, arr_size);
    return 0;
}