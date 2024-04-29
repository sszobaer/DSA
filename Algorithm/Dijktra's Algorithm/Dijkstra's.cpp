#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

// Define a structure to represent a graph edge//
struct Edge {
    int destination;
    int weight;
};

// Define a structure to represent a vertex in the graph
struct Vertex {
    vector<Edge> edges;
};

// Dijkstra's algorithm to find shortest path from source to all other vertices
vector<int> dijkstra(const vector<Vertex>& graph, int source) {
    int numVertices = graph.size();
    vector<int> distance(numVertices, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& edge : graph[u].edges) {
            int v = edge.destination;
            int weight = edge.weight;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

// Function to print the path from source to destination
void printPath(const vector<int>& distance, int source, int destination) {
    if (distance[destination] == INF) {
        cout << "No path from source to destination\n";
        return;
    }

    vector<int> path;
    for (int at = destination; at != source; at = path[at]) {
        path.push_back(at);
    }
    path.push_back(source);

    cout << "Shortest path from " << source << " to " << destination << ": ";
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i > 0) cout << " -> ";
    }
    cout << "\n";
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<Vertex> graph(numVertices);

    cout << "Enter the edges in the format 'source destination weight':\n";
    for (int i = 0; i < numEdges; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source].edges.push_back({destination, weight});
    }

    int source, destination;
    cout << "Enter the source and destination nodes: ";
    cin >> source >> destination;

    vector<int> distance = dijkstra(graph, source);

    printPath(distance, source, destination);

    return 0;
}
