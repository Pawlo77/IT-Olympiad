#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B) {
    if (A[0].size() == B.size()) {
        vector<vector<int>> product(A.size(), vector<int>(B[0].size(), 0));
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B[0].size(); j++)
                for (int k = 0; k < A[0].size(); k++)
                    product[i][j] += A[i][k] * B[k][j];
        return product;
    }
    throw invalid_argument("Ya != Xb");
}

int main() { 
    vector<vector<int>> A = {
        {1, 2},
        {3, 4},
    };
    vector<vector<int>> B = {
        {5, 6},
    };

    vector<vector<int>> C = multiply(A, B);

    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[0].size(); j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}