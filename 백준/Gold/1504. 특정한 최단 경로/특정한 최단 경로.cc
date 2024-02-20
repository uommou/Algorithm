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
    int N, E, v1, v2;
    cin >> N >> E;
    Graph graph(N + 1);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // 양방향 그래프
    }

    cin >> v1 >> v2;

    // 다익스트라 알고리즘을 여러 번 실행하여 필요한 최단 경로 길이를 계산
    vector<int> distFrom1 = dijkstra(graph, 1);
    vector<int> distFromV1 = dijkstra(graph, v1);
    vector<int> distFromV2 = dijkstra(graph, v2);

    // 1->v1->v2->N과 1->v2->v1->N 중 최단 경로 찾기
    long long path1 = (long long)distFrom1[v1] + distFromV1[v2] + distFromV2[N];
    long long path2 = (long long)distFrom1[v2] + distFromV2[v1] + distFromV1[N];
    long long shortestPath = min(path1, path2);

    if (shortestPath >= INF || shortestPath < 0) cout << "-1\n";
    else cout << shortestPath << "\n";

    return 0;
}
