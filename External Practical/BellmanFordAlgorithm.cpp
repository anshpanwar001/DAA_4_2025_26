#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<Edge> graph(edges);
    for (int i = 0; i < edges; i++) {
        cin >> graph[i].u >> graph[i].v >> graph[i].weight;
    }

    int source;
    cin >> source;

    const int INF = 1e9;
    vector<int> distance(vertices, INF);
    distance[source] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        bool updated = false;
        for (const Edge &edge : graph) {
            if (distance[edge.u] == INF) {
                continue;
            }

            if (distance[edge.u] + edge.weight < distance[edge.v]) {
                distance[edge.v] = distance[edge.u] + edge.weight;
                updated = true;
            }
        }

        if (!updated) {
            break;
        }
    }

    for (const Edge &edge : graph) {
        if (distance[edge.u] != INF &&
            distance[edge.u] + edge.weight < distance[edge.v]) {
            cout << "Negative weight cycle detected\n";
            return 0;
        }
    }

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": ";
        if (distance[i] == INF) {
            cout << "INF\n";
        } else {
            cout << distance[i] << '\n';
        }
    }

    return 0;
}
