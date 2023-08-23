#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define a structure to represent a graph edge
struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

// Comparator for the priority queue used in Prim's algorithm
struct CompareEdges {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight; // Min-heap based on edge weight
    }
};

// Function to find the MST using Prim's algorithm
void primMST(vector<vector<Edge>>& graph, int start) {
    int n = graph.size(); // Number of vertices in the graph

    vector<bool> visited(n, false); // To track visited vertices
    priority_queue<Edge, vector<Edge>, CompareEdges> pq; // Priority queue for edges

    // Start with the given vertex
    pq.push(Edge(-1, start, 0)); // -1 represents no parent, weight is 0 for starting vertex

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        int to = current.to;

        if (visited[to]) // Skip if already visited
            continue;

        visited[to] = true;

        if (current.from != -1) {
            cout << "Edge: " << current.from << " - " << current.to << " Weight: " << current.weight << endl;
        }

        // Add adjacent edges to the priority queue
        for (const Edge& edge : graph[to]) {
            if (!visited[edge.to]) {
                pq.push(edge);
            }
        }
    }
}

int main() {
    int n, m; // Number of vertices and edges
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].emplace_back(from, to, weight);
        graph[to].emplace_back(to, from, weight); // Assuming an undirected graph
    }

    int startVertex;
    cin >> startVertex;

    primMST(graph, startVertex);

    return 0;
}
