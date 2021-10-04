#include <bits/stdc++.h>
using namespace std;


/* 
topological sorting for directed acyclic graph
    - linear ordering of verticles such that for every directed 
    edge (u v) u comes bedore v in ordering
*/

void topoSortUtil(int V, vector<int> adj[], vector<bool> &visited, stack<int> &s) {
        if (!visited[V]) {
            visited[V] = 1;
            
            for (auto i : adj[V])
                topoSortUtil(i, adj, visited, s);
                
            s.push(V);
        }
    }
//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<bool> visited(V, 0);
    stack<int> s;
    
    for (int i = 0; i < V; i++)
        topoSortUtil(i, adj, visited, s);
    
    vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    
    return result;
}