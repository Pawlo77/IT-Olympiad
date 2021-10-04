// Given a binary matrix mat of size n * m, 
// find out the maximum size square sub-matrix with all 1s.

int maxSquare(int n, int m, vector<vector<bool>> mat){
    int max = 0;
    
    int size[n][m];
    
    // copyt first col and row to size
    for (int i = 0; i < n; i++) {
        if (mat[i][0]) max = 1;
        size[i][0] = mat[i][0];
    }
    for (int i = 0; i < m; i++) {
        if (mat[0][i]) max = 1;
        size[0][i] = mat[0][i];
    }
    
    for (int i = 1; i < n; i++) 
        for (int j = 1; j < m; j++) {
            if (mat[i][j]) {
                size[i][j] = min(size[i - 1][j], min(
                                    size[i - 1][j - 1],
                                    size[i][j - 1])) + 1;
                if (size[i][j] > max)
                    max = size[i][j];
            }
            else
                size[i][j] = 0;
        }
    
    
    return max;
}