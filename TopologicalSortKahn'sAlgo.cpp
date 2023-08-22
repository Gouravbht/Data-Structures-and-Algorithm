#include <iostream>
#include <vector>
#include <queue>

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

    vector<int> topologicalSort() {
        vector<int> inDegree(vertices, 0);
        for (int vertex = 0; vertex < vertices; ++vertex) {
            for (int neighbor : adjacencyList[vertex]) {
                inDegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int vertex = 0; vertex < vertices; ++vertex) {
            if (inDegree[vertex] == 0) {
                q.push(vertex);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            result.push_back(currentVertex);

            for (int neighbor : adjacencyList[currentVertex]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return result;
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
