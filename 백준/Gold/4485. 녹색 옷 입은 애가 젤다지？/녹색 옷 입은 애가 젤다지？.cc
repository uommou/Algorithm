#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max(); // 무한대를 나타내는 상수
typedef pair<int, int> pii; // 위치 좌표를 저장하기 위한 pair 타입
typedef pair<int, pii> Node; // 비용과 위치 좌표를 함께 저장하기 위한 pair 타입
typedef vector<vector<int>> Matrix; // 그래프(맵)를 저장하는 2차원 벡터 타입

// 다익스트라 알고리즘을 사용하여 문제를 해결하는 함수
vector<vector<int>> dijkstra(const Matrix& graph, int N) {
    vector<vector<int>> dist(N, vector<int>(N, INF)); // 각 칸까지의 최소 비용을 저장하는 2차원 벡터
    priority_queue<Node, vector<Node>, greater<Node>> pq; // 최소 힙을 사용하는 우선순위 큐
    
    // 시작 위치(0, 0)의 비용을 초기화하고 우선순위 큐에 삽입
    dist[0][0] = graph[0][0];
    pq.push({graph[0][0], {0, 0}});

    // 상하좌우 이동을 위한 방향 벡터
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    while (!pq.empty()) {
        int cost = pq.top().first; // 현재 칸까지의 비용
        pii pos = pq.top().second; // 현재 칸의 위치 (y, x)
        pq.pop();

        if (dist[pos.first][pos.second] < cost) continue; // 이미 더 작은 비용으로 방문한 경우

        // 상하좌우 칸을 확인
        for (int i = 0; i < 4; ++i) {
            int ny = pos.first + dy[i];
            int nx = pos.second + dx[i];

            // 맵 범위 내에 있는지 확인
            if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
                int nextCost = cost + graph[ny][nx]; // 다음 칸까지의 총 비용
                if (nextCost < dist[ny][nx]) { // 최소 비용 갱신이 가능한 경우
                    dist[ny][nx] = nextCost;
                    pq.push({nextCost, {ny, nx}}); // 우선순위 큐에 삽입
                }
            }
        }
    }

    return dist; // 모든 칸까지의 최소 비용을 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, problem = 1;
    while (cin >> N && N) { // N이 0이 아닐 때까지 반복
        Matrix graph(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> graph[i][j]; // 도둑루피 정보 입력
            }
        }

        vector<vector<int>> min_cost = dijkstra(graph, N); // 다익스트라 알고리즘 실행
        cout << "Problem " << problem++ << ": " << min_cost[N-1][N-1] << "\n"; // 결과 출력
    }

    return 0;
}
