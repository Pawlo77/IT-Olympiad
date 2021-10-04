#include <bits/stdc++.h>
using namespace std;

#define MAX 255

//Function to modify the matrix such that if a matrix cell matrix[i][j]
//is 1 then all the cells in its ith row and jth column will become 1.
void booleanMatrix(vector<vector<bool> > &matrix) {
    bool r1_flag = 0, c1_flag = 0;
    
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++) {
            if (i == 0 && matrix[0][j])
                r1_flag = 1;
            if (j == 0 && matrix[i][0])
                c1_flag = 1;
                
            if (matrix[i][j]) {
                matrix[0][j] = 1;
                matrix[i][0] = 1;
            }
        }
        
    // modify matrix using data from row 0 and col 0
    for (int i = 1; i < matrix.size(); i++)
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[0][j] || matrix[i][0])
                matrix[i][j] = 1;
        }
        
    // modify first row and first column according to flags
    if (r1_flag)
        for (int i = 0; i < matrix[0].size(); i++)
            matrix[0][i] = r1_flag;
    if (c1_flag)
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = c1_flag;
}

/* ------------------------------------------------------------------------- */
struct Node {
    bool isEnd;
    Node *child[2];
    
    Node() {
        isEnd = 0;
        child[0] = child[1] = NULL;
    }
};

// inserts new row to trie, if it is already present returns 0
bool insert(int M[MAX][MAX], int row, int col, int col_idx, Node **root) {
    if (*root == NULL) 
        *root = new Node();
        
    // recurr if there are more entries in current row
    if (col_idx < col)
        return insert(M, row, col, col_idx + 1, &((*root)->child[M[row][col_idx]]));
    
    if (!((*root)->isEnd)) {
        // uniue row found
        (*root)->isEnd = 1;
        return 1;
    }
    return 0;
}

// function returning unique rows in booleanMatrix
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col) {
    // create a trie
    Node *root = NULL;
    vector<vector<int>> result;
    
    // for each row
    for (int i = 0; i < row; i++) 
        if (insert(M, i, col, 0, &root)) {
            vector<int> temp;
            for (int j = 0; j < col; j++) 
                temp.push_back(M[i][j]);
            result.push_back(temp);
        }
        
    return result;
}

/* ----------------------------------------------------------------*/
// Create a matrix with alternating rectangles of O and X
vector<vector<bool>> generate(int R, int C) {
    vector<vector<bool>> result(R, vector<bool>(C, 0));
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    bool visited[R][C];
    memset(visited, 0, sizeof(visited));

    int r = 0, c = 0, dx = 0;
    bool d = 1;
    for (int i = 0; i < R * C; i++) {
        visited[r][c] = 1;
        result[r][c] = d;

        if (r + dr[dx] >= R || c + dc[dx] >= C || visited[r + dr[dx]][c + dc[dx]]) {
            if (dx == 3) {
                d = !d;
                dx = 0;
            }
            else 
                dx++;
        }
        r += dr[dx];
        c += dc[dx];
    }

    return result;
}

// int main() { 
//     int R = 6, C = 7;
//     vector<vector<bool>> v = generate(R, C);

//     for (int i = 0; i < R ; i++) {
//         for (int j = 0; j < C ; j++)
//             cout << v[i][j] << " ";
//         cout << endl;
//     }
// }

/* ----------------------------------------------------------------*/
// Print all elements in sorted order from 
// row and column wise sorted matrix

struct MinHeapNode {
    int val; // val from field in matrix
    int idx; // column idx
    int next; // idx of next val in column (row idx)
};

void swap(MinHeapNode *x1, MinHeapNode *x2) {
    MinHeapNode temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}

class MinHeap {
    int size;
    MinHeapNode *arr;
public:
    MinHeap(MinHeapNode *a, int s) {
        arr = a;
        size = s;

        int i = (size - 1) / 2;
        while (i >= 0) 
            MinHeapify(i--);
    }

    int left (int i) { return 2 * i + 1; }
    int right (int i) { return 2 * i + 2; }
    MinHeapNode getMin() { return arr[0]; }
    
    void ReplaceMin(MinHeapNode x) { 
        arr[0] = x;
        MinHeapify(0);
    }

    void MinHeapify(int i) {
        int l = left(i), r = right(i);
        int smallest = i;
        if (l < size && arr[l].val < arr[i].val)
            smallest = l;
        if (r < size && arr[r].val < arr[smallest].val)
            smallest = r;
        if (smallest != i) { 
            swap(&arr[i], &arr[smallest]);
            MinHeapify(smallest);
        }
    }
};

vector<vector<int>> sortMatrix(vector<vector<int>> M, int N) {
    MinHeapNode *temp = new MinHeapNode[N];
    for (int i = 0; i < N; i++) {
        temp[i].val = M[i][0];
        temp[i].idx = i;
        temp[i].next = 1;
    }
    MinHeap heap(temp, N);

    MinHeapNode current;
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            current = heap.getMin();
            result[i][j] = current.val;

            if (current.next < N) {
                current.val = M[current.idx][current.next];
                current.next++;
            }
            else 
                current.val = INT_MAX;

            heap.ReplaceMin(current);
        }
    }

    return result;
}

/*----------------------------------------------------------------*/
// Given an n x n square matrix, 
// find sum of all sub-squares of size k x k

void printSum(vector<vector<int>> M, int k) {
    if (k > M.size() || k > M[0].size()) return;

    int stripSum[M.size()][M[0].size()];
    // go by column
    for (int j = 0; j < M[0].size(); j++) {
        // calculate sum of first k fields in this row
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += M[i][j];
        stripSum[0][j] = sum;

        for (int i = 1; i < M.size() - k + 1; i++) {
            sum += M[i + k - 1][j] - M[i - 1][j];
            stripSum[i][j] = sum;
        }
    }

    for (int i = 0; i < M.size() - k + 1; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) 
            sum += stripSum[i][j];
        cout << sum << " ";

        for (int j = 1; j < M[0].size() - k + 1; j++){
            sum += stripSum[i][j + k - 1] - stripSum[i][j - 1];
            cout << sum << " ";
        }
        cout << endl;
    }
}

// int main()
// {
//     vector<vector<int>> mat = {{1, 1, 1, 1, 1},
//                      {2, 2, 2, 2, 2},
//                      {3, 3, 3, 3, 3},
//                      {4, 4, 4, 4, 4},
//                      {5, 5, 5, 5, 5},
//                     };
//     int k = 3;
//     printSum(mat, k);
//     return 0;
// }

/*----------------------------------------------------------------*/
// Find a common element in all rows of a 
// given row-wise sorted matrix

int common(vector<vector<int>> M) {
    int tail[M.size()];
    for (int i = 0; i < M.size(); i++)
        tail[i] = M[0].size() - 1;

    int min_row = 0;
    while(tail[min_row] >= 0) {
        // find minimum in current last column
        for (int i = 0; i < M.size(); i++)
            if (M[i][tail[i]] < M[min_row][tail[min_row]])
                min_row = i;

        int eq_count = 0;
        for (int i = 0; i < M.size(); i++) {
            if (M[i][tail[i]] > M[min_row][tail[min_row]]) {
                if (tail[i] == 0)
                    return -1;
                tail[i]--;
            }
            else
                eq_count++;
        }

        if (eq_count == M.size())
            return M[min_row][tail[min_row]];
    }
    return -1;
}

int main()
{
    vector<vector<int>> mat = {
        { 1, 2, 3, 4, 5 },
        { 2, 4, 5, 8, 10 },
        { 3, 5, 7, 9, 11 },
        { 1, 3, 5, 7, 9 },
    };
    
    cout << common(mat) << endl;
    return 0;
}