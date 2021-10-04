//Function to return a list of integers denoting spiral traversal of matrix.
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)  {
    bool visited[r][c];
    memset(visited, 0, sizeof(visited));
    vector<int> result;

    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    int r_idx = 0, c_idx = 0, d = 0;

    for (int i = 0; i < r * c; i++) {
        result.push_back(matrix[r_idx][c_idx]);
        visited[r_idx][c_idx] = 1;
    
        int next_r = r_idx + dr[d];
        int next_c = c_idx + dc[d];
    
        if (0 <= next_r && next_r < r && 0 <= next_c 
            && next_c < c && !visited[next_r][next_c]) {
            r_idx = next_r;
            c_idx = next_c;
        }
        else {
            d = (d + 1) % 4;
            r_idx += dr[d];
            c_idx += dc[d];
        }
    }

    return result;
}