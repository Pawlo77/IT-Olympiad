bool compare(pair<int, pair<int, int>> p1,
             pair<int, pair<int, int>> p2) {
    // if amount isn't equal
    if (p1.second.second != p2.second.second)
        return p1.second.second > p2.second.second;
    
    // take number that occured first as first
    // return p1.second.first < p2.second.first;
    
    // take number that is smaller first
    return p1.first < p2.first;
}

void sortByFrequency(int a[], int n) {
    // get frequency of each element
    unordered_map<int, pair<int, int>> map;
	for (int i = 0; i < n; i++) {
        if (map.find(a[i]) != map.end())   
            map[a[i]].second++;
        else 
            map[a[i]] = {i, 1};
	}
	
    // copy map to vector and sort it
	vector<pair<int, pair<int, int>>> v;
	for (auto t: map)
	    v.push_back({t.first, t.second});    
	sort(v.begin(), v.end(), compare);

    // copy results to a
    int i = 0;
    for (auto t: v)
        while (t.second.second--)
            a[i++] = t.first;
}