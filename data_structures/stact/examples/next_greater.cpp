/* given a vector of values
return vector containing the next greater
element (first on right) */
vector<long long> nextLargerElement(vector<long long> arr, int n){
    stack<long long> stack;
    vector<long long> result(n);
    
    for (int i = n - 1; i >= 0; i--) {
        if (!stack.empty())
            while (!stack.empty() && stack.top() <= arr[i])
                stack.pop();
                
        result[i] = stack.empty() ? -1 : stack.top();
        stack.push(arr[i]);
    }

    return result;
}