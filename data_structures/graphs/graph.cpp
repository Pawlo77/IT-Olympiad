#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

// Function to return the adjacency list for each vertex.
vector<vector<int>> printGraph(int V, vector<int> adj[]) {
    vector<vector<int>> graph;
    
    for (int i = 0; i < V; i++) {
        vector<int> temp = { i };
        for (auto it : adj[i])
            temp.push_back(it);
        graph.push_back(temp);
    }

    return graph;
}

class Graph {
    int V;
    list<int> *adj;

    public:
        Graph(int x);

        void addEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int x) {
    V: x;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    // mark all verticles as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // create a queue for BFS
    list<int> q;

    // mark current node as visited and enqueue it
    visited[s] = 1;
    q.push_back(s);

    while (!q.empty()) {
        // dequeue a vertex from queue and print it
        s = q.front();
        cout << s << " ";
        q.pop_front();

        for (auto i : adj[s])
            if (!visited[i]) {
                visited[i] = 1;
                q.push_back(i);
            }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}


