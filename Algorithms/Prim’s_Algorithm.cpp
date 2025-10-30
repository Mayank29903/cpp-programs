#include <iostream>
#include <vector>
#include <climits>  // for INT_MAX
using namespace std;

// Prim's Algorithm: Find Minimum Spanning Tree (MST)
void primsAlgorithm(int V, vector<vector<int>> &graph) {
    vector<int> key(V, INT_MAX);   // Minimum weight edge for each vertex
    vector<bool> mstSet(V, false); // True if vertex included in MST
    vector<int> parent(V, -1);     // To store MST structure

    key[0] = 0; // Start from vertex 0

    for (int count = 0; count < V - 1; count++) {
        int minKey = INT_MAX, u;

        // Pick the vertex with the smallest key value not yet included in MST
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = true; // Include this vertex in MST

        // Update the key and parent of adjacent vertices
        for (int v = 0; v < V; v++) {
            // graph[u][v] != 0 means there is an edge
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the Minimum Spanning Tree
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    primsAlgorithm(V, graph);
    return 0;
}
