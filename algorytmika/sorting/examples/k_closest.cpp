#include <iostream>
#include <vector>
using namespace std;

/* Find k closest elements to a given 
value x in sorted array arr of lenght n */

class Solution{   
private:
    int getPos(vector<int> arr, int start, int end, int x) {
        if (arr[end] <= x) {
            return end;
        }
        else if (arr[start] > x) {
            return start;
        }
        
        int mid = (start + end) / 2;
        if (arr[mid] <= x && arr[mid + 1] > x) {
            return mid;
        }
        else if (arr[mid] < x) {
            return getPos(arr, mid + 1, end, x);
        }
        else {
            return getPos(arr, start, mid - 1, x);
        }
    }
    
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        
        // seak for closest val
        int l = getPos(arr, 0, n - 1, x);
        int r = l + 1;
        int count = 0;
        vector<int> result;
        
        if (arr[l] == x) l--;

        while (l >= 0 && r < n && count < k) {
            if (x - arr[l] < arr[r] - x) {
                result.push_back(arr[l--]);
            }
            else {
                result.push_back(arr[r++]);
            }
            count++;
        }

        while (count < k && l >= 0) {
            result.push_back(arr[l--]);
            count++;
        }

        while (count < k && r < n) {
            result.push_back(arr[r++]);
            count++;
        }
        
        return result;
    }
};

int main() {
    int n = 3;
    vector<int> arr = {374, 544, 677};
    int k = 2;
    int x = 54;

    Solution ob;
    vector<int> result = ob.printKClosest(arr, n, k, x);

    for (int i = 0; i < k; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}