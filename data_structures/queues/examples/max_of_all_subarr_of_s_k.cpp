/* 
Sliding Window Maximum (Maximum of all subarrays of size k)
*/

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> solution;
        
        // max element on front
        deque<int> q(k);
        
        int i;
        for (i = 0; i < k; ++i) {
            // get rid off all smaller than current
            while (!q.empty() && arr[i] >= arr[q.back()])
                q.pop_back();
                
            q.push_back(i);
        }

        for (; i < n; ++i) {
            solution.push_back(arr[q.front()]);
            
            // remove all elements out of window
            while (!q.empty() && q.front() <= i - k)
                q.pop_front();
                
            // remove all elements smaller than currently added
            while (!q.empty() && arr[i] >= arr[q.back()])
                q.pop_back();
            
            q.push_back(i);
        }

        solution.push_back(arr[q.front()]);
        return solution;
    }
};