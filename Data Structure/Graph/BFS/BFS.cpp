//Task: Make a BFS tree to represent a adjacency matrix
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int vertices;
    int **adjacencyMatrix;

    Graph(int V) : vertices(V)
    {
        adjacencyMatrix = new int*[V];
        for (int i = 0; i < V; ++i)
            {
            adjacencyMatrix[i] = new int[V];
            for (int j = 0; j < V; ++j)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v)
    {
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }

    void bfs(int startVertex)
    {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i)
        {
            visited[i] = false;
        }

        queue<int> q;

        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty())
            {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (int neighbor = 0; neighbor < vertices; ++neighbor)
                {
                if (adjacencyMatrix[currentVertex][neighbor] == 1 && !visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        delete[] visited;
    }

    ~Graph()
    {
        for (int i = 0; i < vertices; ++i)
        {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }
};

int main()
{

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    cout << "BFS starting from vertex 0: ";
    g.bfs(0);

    return 0;
}
