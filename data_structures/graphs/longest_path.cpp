#include <bits/stdc++.h>
using namespace std;

struct AdjNode {
    int v;
    int weight;

    AdjNode(int x, int y) {
        v = x;
        weight = y;
    }
};

void topoSortUtil(int V, vector<AdjNode> adj[], vector<bool> &visited, stack<int> &s) {
    if (!visited[V]) {
        visited[V] = 1;

        for (auto i : adj[V])
            topoSortUtil(i.v, adj, visited, s);
        
        s.push(V);
    }
}
stack<int> topoSort(int V, vector<AdjNode> adj[]) {
    vector<bool> visited(V, 0);
    stack<int> s;

    for (int i = 0; i < V; ++i)
        topoSortUtil(i, adj, visited, s);

    return s;
}

// function to calculate longest distance between node
// in weighted directed acyclic graph
// start and every other node in the graph.
// start - starting node, V - number of nodes, adj - graph
vector<int> longestDistances(int start, int V, vector<AdjNode> adj[]) {
    vector<int> distance(V, INT_MIN);
    distance[start] = 0;

    stack<int> graph = topoSort(V, adj);

    while (!graph.empty()) {
        int i = graph.top();
        graph.pop();

        if (distance[i] != INT_MIN)
            for (auto j : adj[i])
                if (distance[j.v] < distance[i] + j.weight)
                    distance[j.v] = distance[i] + j.weight;
    }

    return distance;
}

int main() { 
    int V = 6;
    vector<AdjNode> *graph = new vector<AdjNode>[V];

    vector<int> data[] = {
        {0, 1, 5},
        {0, 2, 3},
        {1, 3, 6},
        {1, 2, 2},
        {2, 4, 4},
        {2, 5, 2},
        {2, 3, 7},
        {3, 5, 1},
        {3, 4, -1},
        {4, 5, -2},
    };

    for (auto i : data) {
        AdjNode node(i[1], i[2]);
        graph[i[0]].push_back(node);
    }

    vector<int> longest = longestDistances(1, V, graph);
    for (auto i : longest) 
        if (i == INT_MIN)
            cout << "INF ";
        else
            cout << i << " ";
    cout << endl;

    return 0;
}