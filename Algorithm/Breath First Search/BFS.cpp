#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// BFS Function
vector<string> BFS(vector<vector<int>>& graph, int start, int target) 
{
    int V = graph.size();
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();

        if (current == target) 
        {
            // Reconstruct path
            vector<string> path;
            int node = target;
            while (node != -1) {
                path.push_back(to_string(node));
                node = parent[node];
            }
            // Reverse path
            int left = 0, right = path.size() - 1;
            while (left < right) 
            {
                swap(path[left], path[right]);
                left++;
                right--;
            }
            return path;
        }

        for (int neighbor = 0; neighbor < V; ++neighbor) 
        {
            if (graph[current][neighbor] && !visited[neighbor]) 
            {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }

    return vector<string>();
}

int main() 
{
    //Adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0, 1, 0, 0, 0},  // A
        {0, 0, 1, 0, 0, 0, 1, 0, 0},  // B
        {0, 0, 0, 0, 0, 1, 0, 0, 0},  // C
        {0, 0, 1, 0, 0, 0, 0, 0, 0},  // D
        {0, 0, 1, 1, 0, 0, 0, 0, 0},  // E
        {0, 0, 0, 1, 0, 0, 0, 0, 0},  // F
        {0, 0, 0, 0, 1, 0, 0, 0, 0},  // G
        {0, 0, 0, 1, 0, 0, 0, 0, 1},  // J
        {0, 0, 0, 0, 1, 0 ,1, 0, 0}   // K
    };

    // Vertices mapping
    unordered_map<int, string> vertexMap = {
        {0, "A"}, {1, "B"}, {2, "C"}, {3, "D"},
        {4, "E"}, {5, "F"}, {6, "G"}, {7, "J"}, {8, "K"}
    };

    // Finding path from A to J
    vector<string> path = BFS(graph, 0, 9);

    // Print the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (const auto& row : graph) 
    {
        for (int val : row) 
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // Print the path
    cout << "Path from A to J: ";
    for (const string& vertex : path) 
    {
        cout << vertexMap[stoi(vertex)] << " ";
    }
    cout << endl;

    return 0;
}
