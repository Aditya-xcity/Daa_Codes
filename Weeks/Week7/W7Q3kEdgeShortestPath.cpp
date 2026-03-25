// Question: Find shortest path from source to destination with exactly k edges

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
#define INF INT_MAX

int shortestPathWithKEdges(int graph[MAX][MAX], int V, int source, int dest, int k)
{

    int dp[MAX][MAX];
    int next[MAX][MAX];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = INF;
        }
    }

    dp[source][0] = 0;

    for (int edges = 1; edges <= k; edges++)
    {
        for (int u = 0; u < V; u++)
        {
            if (dp[u][edges - 1] != INF)
            {
                for (int v = 0; v < V; v++)
                {
                    if (graph[u][v] != 0 && dp[u][edges - 1] + graph[u][v] < dp[v][edges])
                    {
                        dp[v][edges] = dp[u][edges - 1] + graph[u][v];
                    }
                }
            }
        }
    }

    if (dp[dest][k] != INF)
        return dp[dest][k];
    else
        return -1;
}

int shortestPathWithKEdges_3D(int graph[MAX][MAX], int V, int source, int dest, int k)
{

    int dp[MAX][MAX];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = INF;
        }
    }

    dp[source][0] = 0;

    for (int edges = 1; edges <= k; edges++)
    {
        for (int v = 0; v < V; v++)
        {
            for (int u = 0; u < V; u++)
            {
                if (graph[u][v] != 0 && dp[u][edges - 1] != INF)
                {
                    if (dp[u][edges - 1] + graph[u][v] < dp[v][edges])
                    {
                        dp[v][edges] = dp[u][edges - 1] + graph[u][v];
                    }
                }
            }
        }
    }

    if (dp[dest][k] != INF)
        return dp[dest][k];
    else
        return -1;
}

void printPath(int graph[MAX][MAX], int V, int source, int dest, int k)
{

    cout << "Path reconstruction requires storing predecessor information in DP table." << endl;
}

int main()
{
    int V;
    cin >> V;

    int graph[MAX][MAX];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    int source, dest, k;
    cin >> source >> dest >> k;

    source--;
    dest--;

    int result = shortestPathWithKEdges(graph, V, source, dest, k);

    if (result == -1)
    {
        cout << "no path of length " << k << " is available" << endl;
    }
    else
    {
        cout << "Weight of shortest path from (" << source + 1 << "," << dest + 1
             << ") with " << k << " edges : " << result << endl;
    }

    return 0;
}