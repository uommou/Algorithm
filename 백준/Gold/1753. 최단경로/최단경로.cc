#include <iostream>
#include <vector>
#include <queue>
#include <climits> // INT_MAX 사용

using namespace std;

typedef pair<int, int> Edge; // (가중치, 도착 정점)
typedef vector<vector<Edge>> AdjacencyList;

vector<int> DijkstraShortestPath(const AdjacencyList& graph, int source_vertex) {
    vector<int> min_distance(graph.size(), INT_MAX);
    min_distance[source_vertex] = 0;

    priority_queue<Edge, vector<Edge>, greater<Edge>> min_heap;
    min_heap.push({0, source_vertex});

    while (!min_heap.empty()) {
        int current_vertex = min_heap.top().second;
        int distance_to_current = min_heap.top().first;
        min_heap.pop();

        if (distance_to_current > min_distance[current_vertex]) continue;

        for (const Edge& adjacent_edge : graph[current_vertex]) {
            int adjacent_vertex = adjacent_edge.second;
            int weight_to_adjacent = adjacent_edge.first;

            int potential_distance = min_distance[current_vertex] + weight_to_adjacent;
            if (potential_distance < min_distance[adjacent_vertex]) {
                min_distance[adjacent_vertex] = potential_distance;
                min_heap.push({potential_distance, adjacent_vertex});
            }
        }
    }

    return min_distance;
}

int main() {
    ios_base::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    AdjacencyList graph(V+1); // 정점 번호가 1부터 시작하므로 V+1 크기 할당

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v}); // u에서 v로 가는 가중치 w인 간선 추가
    }

    vector<int> min_distance = DijkstraShortestPath(graph, K); // K번 정점에서 시작

    for (int vertex = 1; vertex < min_distance.size(); ++vertex) {
        if (min_distance[vertex] == INT_MAX) {
            cout << "INF\n";
        } else {
            cout << min_distance[vertex] << "\n";
        }
    }

    return 0;
}
