#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

// declare function
vector<string> DFS(vector<vector<int>> &graph, int start, int target) {
    int v = graph.size();
    stack<int> stk;
    vector<bool> visited(v, false);
    vector<int> parent(v, -1);
    stk.push(start);
    visited[start] = true;

    // find path
    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();

        if (current == target) {
            // reconstruct path
            vector<string> path;
            int node = target;
            while (node != -1) {
                path.push_back(to_string(node));
                node = parent[node];
            }
            // reverse path
            int left = 0, right = path.size() - 1;
            while (left < right) {
                swap(path[left], path[right]);
                left++;
                right--;
            }
            return path;
        }
        for (int i = 0; i < v; i++) {
            if (graph[current][i] && !visited[i]) {
                stk.push(i);
                visited[i] = true;
                parent[i] = current;
            }
        }
    }
    return vector<string>();
}

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    // input graph matrix
    vector<vector<int>> graph(v, vector<int>(v));
    cout << "Enter the adjacency matrix of the graph:" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> graph[i][j];
        }
    }

    // vertex mapping
    unordered_map<int, string> vertexMap;
    cout << "Enter vertex names:" << endl;
    for (int i = 0; i < v; i++) {
        string vertexName;
        cout << "Vertex " << i << ": ";
        cin >> vertexName;
        vertexMap[i] = vertexName;
    }

    int start, target;
    cout << "Enter the start vertex: ";
    cin >> start;
    cout << "Enter the target vertex: ";
    cin >> target;

    // find path
    vector<string> path = DFS(graph, start, target);

    if (path.empty()) {
        cout << "No path found from vertex " << start << " to vertex " << target << endl;
    } else {
        cout << "Path from " << vertexMap[start] << " to " << vertexMap[target] << ": ";
        for (const string& vertex : path) {
            cout << vertexMap[stoi(vertex)] << "\t";
        }
        cout << endl;
    }

    return 0;
}
