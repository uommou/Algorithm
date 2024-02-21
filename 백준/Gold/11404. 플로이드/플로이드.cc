#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
typedef pair<int, int> pii;

vector<int> dijkstra(const vector<vector<pii>>& graph, int src) {
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

        for (const auto& edge : graph[current]) {
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
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n+1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    for (int i = 1; i <= n; ++i) {
        vector<int> min_cost = dijkstra(graph, i);
        for (int j = 1; j <= n; ++j) {
            if (i == j) cout << "0 ";
            else if (min_cost[j] == INF) cout << "0 ";
            else cout << min_cost[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
