#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>
#include <unordered_map>

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

    vector<int> aStar(int source, int destination);
    void printPath(const unordered_map<int, int>& cameFrom, int source, int destination, const vector<int>& distance);
    static double Heuristic(int a, int b);
};

vector<int> Graph::aStar(int source, int destination) {
    vector<int> distance(V, numeric_limits<int>::max());
    unordered_map<int, int> cameFrom;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            int newCost = distance[u] + weight;
            if (newCost < distance[v]) {
                distance[v] = newCost;
                cameFrom[v] = u;
                pq.push({newCost + Heuristic(v, destination), v});
            }
        }
    }

    printPath(cameFrom, source, destination, distance);

    return distance;
}

void Graph::printPath(const unordered_map<int, int>& cameFrom, int source, int destination, const vector<int>& distance) {
    cout << "Fastest path from " << source << " to " << destination << ": ";

    int current = destination;
    vector<int> path;

    while (current != source) {
        path.push_back(current);
        current = cameFrom.at(current);
    }
    path.push_back(source);

    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i > 0) {
            cout << " -> ";
        }
    }

    cout << " with cost: " << distance[destination] << endl;
}

double Graph::Heuristic(int a, int b) {
    int ax = a % 5;
    int ay = a / 5;
    int bx = b % 5;
    int by = b / 5;
    return abs(ax - bx) + abs(ay - by);
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

    vector<int> distances = graph.aStar(source, destination);

    return 0;
}
