vector<int> common_element(vector<int> v1,vector<int> v2) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    vector<int> output;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] == v2[j]) {
            output.push_back(v1[i]);
            i++;
            j++;
        } else if (v1[i] > v2[j])
            j++;
        else
            i++;
    }
    return output;
}