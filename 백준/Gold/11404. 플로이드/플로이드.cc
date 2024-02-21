#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// 플로이드-워셜 알고리즘 함수
void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; ++k) { // 경유하는 정점
        for (int i = 0; i < n; ++i) { // 시작 정점
            for (int j = 0; j < n; ++j) { // 도착 정점
                // 경유해서 가는 비용이 더 저렴한 경우, 비용을 업데이트
                if (dist[i][k] < INF && dist[k][j] < INF) { 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> dist(n, vector<int>(n, INF));
    
    for (int i = 0; i < n; ++i) dist[i][i] = 0;
    
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; // 인덱스를 0부터 시작하도록 조정
        dist[a][b] = min(dist[a][b], c);
    }
    
    // 플로이드-워셜 알고리즘을 사용하여 모든 정점 쌍의 최단 거리를 계산합니다.
    floydWarshall(dist, n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                cout << 0 << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

