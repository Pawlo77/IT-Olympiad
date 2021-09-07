#include <iostream>
using namespace std;

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void insertion_sort(int arr[], int n, int k) {
    int j, key;
    for(int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int t;
    for (cin >> t; t > 0; t--) {
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        insertion_sort(arr, n, k);
        
        print_arr(arr, n);
        cout << endl;
    }

	return 0;
}