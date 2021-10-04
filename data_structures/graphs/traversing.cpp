/*----------------------------------------------------------------
To rewrite below functions to work on unlined graph 
(where all nodes aren't reachable from node 0) just iterate over 
all nodes and call BFS or DFS whenever the node weren't already visited
----------------------------------------------------------------*/

 // Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;
        
    vector<int> result;
    
    int c = 0;
    queue<int> q;
    q.push(c);
    visited[c] = 1;
    
    while (!q.empty()) {
        c = q.front(); q.pop();
        result.push_back(c);
        
        for (auto i : adj[c]) 
            if (!visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
    }
    
    return result;
}

void DFSUtil(int i, vector<int> adj[], vector<bool> &visited, vector<int> &result) {
        visited[i] = 1;
        result.push_back(i);
        
        for (auto j : adj[i])
            if (!visited[j])
                DFSUtil(j, adj, visited, result);
    }
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> result;
    vector<bool> visited(V, 0);
    
    DFSUtil(0, adj, visited, result);
    
    return result;
}

/*----------------------------------------------------------------*/
