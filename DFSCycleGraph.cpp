#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
    }

    bool hasCycleDFS(int vertex, vector<bool>& visited, vector<bool>& recStack) {
        visited[vertex] = true;
        recStack[vertex] = true;

        for (int neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor]) {
                if (hasCycleDFS(neighbor, visited, recStack)) {
                    return true;
                }
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[vertex] = false;
        return false;
    }

    bool hasCycle() {
        vector<bool> visited(vertices, false);
        vector<bool> recStack(vertices, false);

        for (int vertex = 0; vertex < vertices; ++vertex) {
            if (!visited[vertex]) {
                if (hasCycleDFS(vertex, visited, recStack)) {
                    return true;
                }
            }
        }

        return false;
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

    if (g.hasCycle()) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
