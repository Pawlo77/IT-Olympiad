#include <bits/stdc++.h>
using namespace std;
 
bool isBipartite(int V, vector<int>adj[]){
    vector<int> color(V, -1);
    queue<int> q;
    
    int current;
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);
            
            while (!q.empty()) {
                current = q.front(); q.pop();
                
                for (int j : adj[current]) {
                    if (color[current] == color[j])
                        return false;
                        
                    if (color[j] == -1) {
                        color[j] = 1 - color[current];
                        q.push(j);
                    }
                }
            }
        }
    }
    
    return 1;
}