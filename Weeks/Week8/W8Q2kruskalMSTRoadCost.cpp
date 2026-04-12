// Question: Find minimum cost to connect cities using Kruskal's Algorithm (MST)

// Name - ADITYA BHARDWAJ
// Section - D2
// Roll No - 07
// Course – B TECH
// Branch – CSE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int node, int parent[]) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, int parent[]) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    parent[u] = v;
}

int main() {
    int V;
    cout << "Enter number of cities: ";
    cin >> V;

    int graph[100][100];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    // Symmetrize the matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (graph[i][j] != 0 && graph[j][i] == 0)
                graph[j][i] = graph[i][j];

    vector<Edge> edges;

    // Convert matrix to edge list (upper triangle only, after symmetry fix)
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (graph[i][j] != 0)
                edges.push_back({i, j, graph[i][j]});

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    int parent[100];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    int count = 0;

    cout << "\nEdges in MST:\n";
    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;

        if (findParent(u, parent) != findParent(v, parent)) {
            unionSet(u, v, parent);
            totalCost += edge.weight;
            count++;
            cout << u << " - " << v << " : " << edge.weight << "\n";

            if (count == V - 1)
                break;
        }
    }

    cout << "Minimum Spanning Weight: " << totalCost << "\n";

    return 0;
}