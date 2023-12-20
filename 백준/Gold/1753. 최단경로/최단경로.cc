#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
typedef pair<int, int> pii;

int main() {
    int V, E, K;
    cin >> V >> E >> K;
    vector<vector<pii>> graph(V + 1);
    vector<int> distance(V + 1, INF);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, K});
    distance[K] = 0;

    while (!pq.empty()) {
        int dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (distance[current] < dist) continue;

        for (auto& edge : graph[current]) {
            int next = edge.first;
            int nextDist = dist + edge.second;
            if (nextDist < distance[next]) {
                distance[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (distance[i] == INF) cout << "INF\n";
        else cout << distance[i] << '\n';
    }

    return 0;
}
