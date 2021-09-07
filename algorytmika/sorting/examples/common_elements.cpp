#include <iostream>
#include <vector>
using namespace std;

/* Find common elements in three sorted arrays */

void find(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3) {
    int x = 0, y = 0, z = 0;
    vector<int> solution;

    while  (x < n1 && y < n2 && z < n3) {
        if (arr1[x] == arr2[y] && arr2[y] == arr3[z]) {
            solution.push_back(arr1[x]);
            x++; y++; z++;
        }
        else if (arr1[x] < arr2[y])
            x++;
        else if (arr2[y] < arr3[z])
            y++;
        else
            z++;
    }

    for (vector<int>::iterator i = solution.begin(); i != solution.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

}

int main() {
    int ar1[] = {1, 5, 10, 20, 40, 80};
    int ar2[] = {6, 7, 20, 80, 100};
    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    int n3 = sizeof(ar3)/sizeof(ar3[0]);
 
    find(ar1, ar2, ar3, n1, n2, n3);

    return 0;
}