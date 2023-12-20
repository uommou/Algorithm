#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // 인접 리스트
vector<bool> visited;    // 방문 여부 체크

void dfs(int node) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // 양방향 연결
    }

    dfs(1); // 1번 컴퓨터부터 시작

    int infected = 0;
    for (int i = 2; i <= n; i++) { // 1번 컴퓨터 제외
        if (visited[i]) {
            infected++;
        }
    }

    cout << infected << endl;
    return 0;
}
