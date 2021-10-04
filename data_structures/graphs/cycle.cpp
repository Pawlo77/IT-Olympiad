#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dst;
};

class Graph {
    public:
        // number of verticles, edges
        int V, E;
        int count; // number of edges already connected

        Edge* graph;

        Graph(int x, int y) { 
            V = x;
            E = y;

            count = 0;

            graph = new Edge[E * sizeof(Edge)];
        }

        void addEdge(int s, int d) {
            graph[count].src = s;
            graph[count].dst = d;
            count++;
        }

        // function to find the subset of an element i
        int find(vector<int> parent, int i) { 
            if (parent[i] == -1)
                return i;
            return find(parent, parent[i]);
        }

        // function to do union of two subsets
        void Union(vector<int> &parent, int x, int y) { 
            parent[x] = y;
        }

        bool isCycle() { 
            vector<int> parent(V, -1);

            for (int i = 0; i < E; i++) {
                int x = find(parent, graph[i].src);
                int y = find(parent, graph[i].dst);
                
                if (x == y) return 1;
                Union(parent, x, y);
            }
            return 0;
        }
};

int main() { 
    Graph g(3, 3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 2);

    cout << g.isCycle() << endl;

    return 0;
}


/*--------------------------------------------------------------*/
//for adj representation of graph


bool isCycleUtil(int V, vector<int> adj[], vector<bool> &visited, int parent) {
        visited[V] = 1;
        
        for (auto i : adj[V]) {
            if (!visited[i]) {
                if (isCycleUtil(i, adj, visited, V))
                    return 1;
            }
            else if (i != parent)
                return 1;
        }
        return 0;
    }
// Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, 0);
        
        // iterate over each edge
        for (int i = 0; i < V; i++)
            if (!visited[i])
                if (isCycleUtil(i, adj, visited, -1))
                    return 1;
        return 0;
    }


bool isCyclicUtil(int i, vector<int> adj[], vector<bool> &visited, vector<bool> &recursion) {
    if (!visited[i]) {
        visited[i] = 1;
        recursion[i] = 1;
        
        for (auto j : adj[i]) {
            if (!visited[j] && isCyclicUtil(j, adj, visited, recursion))
                return 1;
            else if (recursion[j])
                return 1;
        }
    }
    recursion[i] = 0;
    return 0;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V, 0);
    vector<bool> recursion(V, 0);
    
    for (int i = 0; i < V; i++)
        if (isCyclicUtil(i, adj, visited, recursion)) 
            return 1;
    return 0;
}