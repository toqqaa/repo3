#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adjList; 

    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); 
    }

    vector<int> dijkstra(int source, int destination);
    void printPath(const vector<int>& parent, int source, int destination, const vector<int>& distance);
};

vector<int> Graph::dijkstra(int source, int destination) {
    vector<int> distance(V, numeric_limits<int>::max());
    vector<int> parent(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    printPath(parent, source, destination, distance);

    return distance;
}

void Graph::printPath(const vector<int>& parent, int source, int destination, const vector<int>& distance) {
    cout << "Shortest path from " << source << " to " << destination << ": ";

    int current = destination;
    vector<int> path;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i > 0) {
            cout << " -> ";
        }
    }

    cout << " with cost: " << distance[destination] << endl;
}

int main() {
  Graph graph(12);

    // Adding edges and weights
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 3, 101);
    graph.addEdge(1, 2, 4);
    graph.addEdge(1, 4, 13);
    graph.addEdge(2, 5, 8);
    graph.addEdge(3, 4, 110);
    graph.addEdge(3, 6, 101);
    graph.addEdge(4, 5, 18);
    graph.addEdge(4, 7, 30);
    graph.addEdge(5, 8, 12);
    graph.addEdge(6, 7, 20);
    graph.addEdge(6, 9, 1);
    graph.addEdge(7, 8, 24);
    graph.addEdge(7, 10, 21);
    graph.addEdge(8, 11, 5);
    graph.addEdge(9, 10, 2);
    graph.addEdge(10, 11, 2);

    int source = 6;
    int destination = 2;

    vector<int> distances = graph.dijkstra(source, destination);

    return 0;
}