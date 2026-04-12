// Question: Find minimum cost to connect cities using Prim's Algorithm (MST)

// Name - ADITYA BHARDWAJ
// Section - D2
// Roll No - 07
// Course – B TECH
// Branch – CSE

#include <iostream>
#include <climits>
using namespace std;

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

int primMST(int V, int graph[][100]) {
    int parent[100];
    int key[100];
    bool mstSet[100];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;
    for (int i = 1; i < V; i++)
        total += key[i];

    return total;
}

int main() {
    cout << "VERSION 4\n";   // ← will confirm new exe is running

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

    // Debug: print symmetrized matrix
    cout << "\nSymmetrized matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }

    cout << "\nMinimum Spanning Weight: " << primMST(V, graph) << "\n";

    return 0;
}