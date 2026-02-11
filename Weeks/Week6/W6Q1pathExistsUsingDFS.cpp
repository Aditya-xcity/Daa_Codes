// Given a (directed/undirected) graph, design an algorithm and implement it using a program to
// find if a path exists between two given vertices or not using DFS.

/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
using namespace std;

void dfs(int graph[100][100], int n, int current, int destination, bool visited[], bool &found) {
    if (current == destination) {
        found = true;
        return;
    }

    visited[current] = true;

    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            dfs(graph, n, i, destination, visited, found);
        }
    }
}

int main() {
    int n;
    cin >> n;

    int graph[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int source, destination;
    cin >> source >> destination;

    source--;
    destination--;

    bool visited[100] = {false};
    bool found = false;

    dfs(graph, n, source, destination, visited, found);

    if (found)
        cout << "Yes Path Exists";
    else
        cout << "No Such Path Exists";

    return 0;
}
