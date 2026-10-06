#include <iostream>
#include <climits>
using namespace std;

void dijkstra(int graph[10][10], int source, int n)
{
    int distance[10];
    bool visited[10];

   
    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    
    distance[source] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        // Find unvisited vertex with minimum distance
        int u = -1;
        int minDistance = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && distance[i] < minDistance)
            {
                minDistance = distance[i];
                u = i;
            }
        }

       
        if (u == -1)
            break;

        visited[u] = true;

       
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

 
    cout << "\nShortest distances from source vertex "
         << source << ":\n";

    for (int i = 0; i < n; i++)
    {
        if (distance[i] == INT_MAX)
            cout << "Vertex " << i << " : INF" << endl;
        else
            cout << "Vertex " << i << " : " << distance[i] << endl;
    }
}

int main()
{
    int n, source;
    int graph[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (0 means no edge):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(graph, source, n);

    return 0;
}
