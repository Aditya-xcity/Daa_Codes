// Question: Floyd Warshall All Pair Shortest Path Algorithm

// Name - ADITYA BHARDWAJ
// Section - D2
// Roll No - 07
// Course – B TECH
// Branch – CSE

#include <iostream>
#include <climits>
#include <string>
using namespace std;

#define INF INT_MAX

void floydWarshall(int dist[][100], int V) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int dist[100][100];

    cout << "Enter adjacency matrix (INF for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            string val;
            cin >> val;
            if (val == "INF")
                dist[i][j] = INF;
            else
                dist[i][j] = stoi(val);
        }
    }

    floydWarshall(dist, V);

    cout << "\nShortest Distance Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF";
            else
                cout << dist[i][j];
            if (j < V - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}