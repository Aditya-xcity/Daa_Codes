// Question: Implement Bellman-Ford Algorithm using arrays to find shortest path and distance from each friend's location to Akshay's house

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
#define MAXE 10000

struct Edge
{
    int u, v, w;
};

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

void bellmanFord(Edge edges[], int E, int n, int source)
{
    int dist[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool updated = false;

        for (int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                updated = true;
            }
        }

        if (!updated)
            break;
    }

    for (int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Graph contains negative weight cycle" << endl;
            return;
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

            cout << i + 1 << " : No path" << endl;
        }
        else
        {

            cout << i + 1 << " : ";
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
    Edge edges[MAXE];
    int E = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] != 0)
            {
                edges[E].u = i;
                edges[E].v = j;
                edges[E].w = graph[i][j];
                E++;
            }
        }
    }

    int source;
    cin >> source;

    bellmanFord(edges, E, n, source - 1);

    return 0;
}