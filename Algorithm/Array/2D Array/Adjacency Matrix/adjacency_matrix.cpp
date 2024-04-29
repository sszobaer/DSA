#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Function for edge
void addEdge(vector<vector<int>> &adjMatrix, int u, int v, int weight = 1) {
    // Adding edge
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

// Function for adjacency matrix
void printAdjMatrix(vector<vector<int>> &adjMatrix) {
    cout << "Adjacency Matrix:\n";
    for (const auto &row : adjMatrix) {
        for (int weight : row) {
            cout << weight << " ";
        }
        cout << endl;
    }
}

// Function for adjacency list
void printAdjList(vector<vector<pair<int, int>>> &adjList) {
    cout << "Adjacency List:\n";
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i << " -> ";
        for (const auto &neighbor : adjList[i]) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5;


    vector<vector<int>> adjMatrix_directed(V, vector<int>(V, 0));
    vector<vector<int>> adjMatrix_undirected(V, vector<int>(V, 0));
    vector<vector<int>> adjMatrix_weighted_directed(V, vector<int>(V, 0));
    vector<vector<int>> adjMatrix_weighted_undirected(V, vector<int>(V, 0));

    vector<vector<pair<int, int>>> adjList_directed(V);
    vector<vector<pair<int, int>>> adjList_undirected(V);
    vector<vector<pair<int, int>>> adjList_weighted_directed(V);
    vector<vector<pair<int, int>>> adjList_weighted_undirected(V);


    addEdge(adjMatrix_directed, 0, 1);
    addEdge(adjMatrix_directed, 0, 2);
    addEdge(adjMatrix_directed, 1, 3);
    addEdge(adjMatrix_directed, 2, 4);
    addEdge(adjMatrix_directed, 3, 4);

    addEdge(adjMatrix_undirected, 0, 1);
    addEdge(adjMatrix_undirected, 0, 2);
    addEdge(adjMatrix_undirected, 1, 3);
    addEdge(adjMatrix_undirected, 2, 4);
    addEdge(adjMatrix_undirected, 3, 4);

    addEdge(adjMatrix_weighted_directed, 0, 1, 3);
    addEdge(adjMatrix_weighted_directed, 0, 2, 5);
    addEdge(adjMatrix_weighted_directed, 1, 3, 2);
    addEdge(adjMatrix_weighted_directed, 2, 4, 7);
    addEdge(adjMatrix_weighted_directed, 3, 4, 4);

    addEdge(adjMatrix_weighted_undirected, 0, 1, 3);
    addEdge(adjMatrix_weighted_undirected, 0, 2, 5);
    addEdge(adjMatrix_weighted_undirected, 1, 3, 2);
    addEdge(adjMatrix_weighted_undirected, 2, 4, 7);
    addEdge(adjMatrix_weighted_undirected, 3, 4, 4);

    // Convert adjacency matrices to adjacency lists
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (adjMatrix_directed[i][j] != 0)
                adjList_directed[i].emplace_back(j, adjMatrix_directed[i][j]);
            if (adjMatrix_undirected[i][j] != 0)
                adjList_undirected[i].emplace_back(j, adjMatrix_undirected[i][j]);
            if (adjMatrix_weighted_directed[i][j] != 0)
                adjList_weighted_directed[i].emplace_back(j, adjMatrix_weighted_directed[i][j]);
            if (adjMatrix_weighted_undirected[i][j] != 0)
                adjList_weighted_undirected[i].emplace_back(j, adjMatrix_weighted_undirected[i][j]);
        }
    }

    // Print adjacency matrices and adjacency lists
    printAdjMatrix(adjMatrix_directed);
    printAdjList(adjList_directed);

    printAdjMatrix(adjMatrix_undirected);
    printAdjList(adjList_undirected);

    printAdjMatrix(adjMatrix_weighted_directed);
    printAdjList(adjList_weighted_directed);

    printAdjMatrix(adjMatrix_weighted_undirected);
    printAdjList(adjList_weighted_undirected);

    return 0;
}
