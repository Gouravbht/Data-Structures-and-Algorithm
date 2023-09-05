#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
  int u, v, w;
};

bool cmp(Edge e1, Edge e2) {
  return e1.w < e2.w;
}

void kruskal(vector<Edge> edges, int n) {
  // Create a forest of n trees.
  vector<int> parent(n, -1);

  // Create a priority queue of edges.
  priority_queue<Edge, vector<Edge>, decltype(&cmp)> pq(cmp);
  for (Edge edge : edges) {
    pq.push(edge);
  }

  // Iterate over all edges.
  while (!pq.empty()) {
    Edge edge = pq.top();
    pq.pop();

    // Check if the edge connects two different trees.
    int u = edge.u;
    int v = edge.v;
    int pu = find(parent, u);
    int pv = find(parent, v);
    if (pu != pv) {
      // The edge connects two different trees. Add it to the forest.
      union(parent, pu, pv);

      // Print the edge.
      cout << u << " - " << v << " " << edge.w << endl;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<Edge> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {u, v, w};
  }

  kruskal(edges, n);

  return 0;
}
