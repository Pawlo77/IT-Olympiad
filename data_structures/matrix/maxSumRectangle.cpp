// Given a 2D array, find the maximum sum subarray in it
int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
    int temp[R], temp2[R];
    int max = INT_MIN;
    int current, sum;
    
    
    for (int left = 0; left < C; left++)
        for (int right = left; right < C; right++) {
            // it is first iteration, copy column to temp
            if (right == left)
                for (int i = 0; i < R; i++) 
                    temp[i] = M[i][right];
            else 
                for (int i = 0; i < R; i++)
                    temp[i] += M[i][right];
                    
            // perform kadane's algorith, on temp
            current = sum = temp[0];
            for (int i = 1; i < R; i++) {
                if (sum + temp[i] > temp[i])
                    sum += temp[i];
                else 
                    sum = temp[i];
                    
                if (sum > current)
                        current = sum;
            }
                
            if (current > max)
                max = current;
        }
        
    return max;
}