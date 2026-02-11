// Given a directed graph, design an algorithm and implement it using a program to find whether cycle exists in the graph or not.

/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
using namespace std;

bool dfs(int graph[100][100], int n, int node, bool visited[], bool recStack[]) {

    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < n; i++) {

        if (graph[node][i] == 1) {

            if (!visited[i] && dfs(graph, n, i, visited, recStack))
                return true;

            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = false;
    return false;
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

    bool visited[100] = {false};
    bool recStack[100] = {false};

    bool cycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(graph, n, i, visited, recStack)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << "Yes Cycle Exists";
    else
        cout << "No Cycle Exists";

    return 0;
}
