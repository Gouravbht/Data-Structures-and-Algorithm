#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    // Function to add a directed edge between vertices u and v
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
    }

    // Depth-First Search for topological sort
    void dfsTopologicalSort(int vertex, vector<bool>& visited, stack<int>& result) {
        visited[vertex] = true;

        // Visit neighbors recursively
        for (int neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor]) {
                dfsTopologicalSort(neighbor, visited, result);
            }
        }

        // Push the current vertex to the result stack
        result.push(vertex);
    }

    // Perform topological sort using DFS
    vector<int> topologicalSort() {
        vector<bool> visited(vertices, false);
        stack<int> result;

        // Iterate through all vertices and perform DFS if not visited
        for (int vertex = 0; vertex < vertices; ++vertex) {
            if (!visited[vertex]) {
                dfsTopologicalSort(vertex, visited, result);
            }
        }

        vector<int> sortedVertices;
        // Pop elements from the stack to get the topological sort order
        while (!result.empty()) {
            sortedVertices.push_back(result.top());
            result.pop();
        }

        return sortedVertices;
    }
};

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    Graph g(numVertices);

    cout << "Enter the edges (vertex u and vertex v):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<int> sortedVertices = g.topologicalSort();

    cout << "Topological Sort Order: ";
    for (int vertex : sortedVertices) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
