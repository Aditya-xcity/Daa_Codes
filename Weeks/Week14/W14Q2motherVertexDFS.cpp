/*Aim: To find the mother vertex in a directed graph using DFS

Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <bits/stdc++.h>
using namespace std;

void DFS(int v, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            DFS(u, adj, visited);
        }
    }
}

int findMotherVertex(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    int lastV = 0;


    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, adj, visited);
            lastV = i;
        }
    }

    // Step 2: Check if lastV is mother vertex
    fill(visited.begin(), visited.end(), false);
    DFS(lastV, adj, visited);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return -1;
        }
    }

    return lastV;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int result = findMotherVertex(V, adj);

    if (result == -1)
        cout << "No mother vertex" << endl;
    else
        cout << "Mother vertex is: " << result << endl;

    return 0;
}