#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> build_time;
vector<vector<int>> adj;
vector<int> indegree;
vector<int> min_time;

void calculate_min_time() {
    queue<int> q;
    // 초기 선행 건물이 없는 건물들을 큐에 추가
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            min_time[i] = build_time[i];
        }
    }

    // 위상 정렬 알고리즘 적용
    for (int i = 1; i <= n; ++i) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            min_time[next] = max(min_time[next], min_time[curr] + build_time[next]);
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n;
    build_time.resize(n + 1);
    adj.resize(n + 1);
    indegree.resize(n + 1, 0);
    min_time.resize(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> build_time[i];
        int prerequisite;
        while (true) {
            cin >> prerequisite;
            if (prerequisite == -1) break;
            adj[prerequisite].push_back(i);
            indegree[i]++;
        }
    }

    calculate_min_time();

    for (int i = 1; i <= n; ++i) {
        cout << min_time[i] << "\n";
    }

    return 0;
}
