// search in sorted matrix (row ascending, col ascending)
int matSearch (int N, int M, int matrix[][M], int x) {
    // if x is larger than largest val or smaller than smallest val
    if (x > matrix[N - 1][M - 1] || x < matrix[0][0])
        return 0;
        
    int i = 0, j = M - 1;
    while (i < N && j >= 0) {
        if (matrix[i][j] == x)
            return 1;
        if (matrix[i][j] > x)
            j--;
        else
            i++;
    }  
    return 0;
}