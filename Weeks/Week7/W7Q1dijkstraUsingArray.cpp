// Question: Implement Dijkstra's Algorithm using arrays to find shortest path and distance from each friend's location to Akshay's house

/*
Name - ADITYA BHARDWAJ
Section - D2
Roll No - 07
Course – B TECH
Branch – CSE
*/

#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

void printPath(int parent[], int current, int source)
{
    if (current == source)
    {
        cout << current + 1;
        return;
    }

    printPath(parent, parent[current], source);
    cout << " " << current + 1;
}

void dijkstra(int graph[MAX][MAX], int n, int source)
{
    int dist[MAX];
    bool visited[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++)
    {

        int u = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {

            if (graph[u][v] != 0 && !visited[v] && dist[u] != INT_MAX)
            {
                if (dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == source)
        {

            cout << i + 1 << " : 0" << endl;
        }
        else if (dist[i] == INT_MAX)
        {

            cout << "No path" << endl;
        }
        else
        {

            printPath(parent, i, source);
            cout << " : " << dist[i] << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int graph[MAX][MAX];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int source;
    cin >> source;

    dijkstra(graph, n, source - 1);

    return 0;
}