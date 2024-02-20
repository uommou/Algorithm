#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

vector<int> dijkstra(const Graph& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dist[current] < currentDist) continue;

        for (auto& edge : graph[current]) {
            int next = edge.first, nextDist = currentDist + edge.second;
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, K;
    cin >> V >> E >> K;
    Graph graph(V + 1);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> min_distance = dijkstra(graph, K);

    for (int i = 1; i <= V; ++i) {
        if (min_distance[i] == INF) cout << "INF\n";
        else cout << min_distance[i] << "\n";
    }

    return 0;
}
