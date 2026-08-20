#include <iostream>
using namespace std;

#define MAX 100

int queueArr[MAX];
int front = -1;
int rear = -1;

int visited[MAX];

void ENQUEUE(int vertex)
{
    if (rear == MAX - 1)
    {
        return; 
    }

    if (front == -1)
    {
        front = 0;
    }

    rear = rear + 1;
    queueArr[rear] = vertex;
}

int DEQUEUE()
{
    if (front == -1)
    {
        return -1;
    }

    int vertex = queueArr[front];

    if (front >= rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = front + 1;
    }

    return vertex;
}

void BFS(int graph[MAX][MAX], int startVertex, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    ENQUEUE(startVertex);
    visited[startVertex] = 1;

    cout << "BFS Traversal: ";

    while (front != -1)
    {
        int currentVertex = DEQUEUE();

        cout << currentVertex << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (graph[currentVertex][i] == 1 &&
                visited[i] == 0)
            {
                ENQUEUE(i);
                visited[i] = 1;
            }
        }
    }

    cout << endl;
}

int main()
{
    int vertices;
    int graph[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter adjacency matrix:" << endl;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    int startVertex;

    cout << "Enter starting vertex: ";
    cin >> startVertex;

    BFS(graph, startVertex, vertices);

    return 0;
}


// OUTPUT:
// Enter number of vertices: 4
// Enter adjacency matrix:
// 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
// Enter starting vertex: 0
// BFS Traversal: 0 1 2 3 
