// Given a graph, design an algorithm and implement it using a program to find if a graph is bipartite or not using BFS.

/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    int graph[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int color[100];
    for (int i = 0; i < n; i++)
        color[i] = -1;

    bool isBipartite = true;

    for (int start = 0; start < n; start++) {

        if (color[start] == -1) {

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                for (int i = 0; i < n; i++) {

                    if (graph[current][i] == 1) {

                        if (color[i] == -1) {
                            color[i] = 1 - color[current];
                            q.push(i);
                        }
                        else if (color[i] == color[current]) {
                            isBipartite = false;
                            break;
                        }
                    }
                }

                if (!isBipartite)
                    break;
            }
        }

        if (!isBipartite)
            break;
    }

    if (isBipartite)
        cout << "Yes Bipartite";
    else
        cout << "Not Bipartite";

    return 0;
}
