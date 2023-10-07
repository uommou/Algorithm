#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[1001];
vector<int> dfs_visited(1001, false);
vector<int> bfs_visited(1001, false);


void dfs(int V) {
	dfs_visited[V] = true;
	cout << V << " ";
	for (int i = 0; i < graph[V].size(); i++) {
		int n = graph[V][i];
		if (!dfs_visited[n]) {
			dfs(n);
		}
	}
}

void bfs(int V) {
	queue<int> q;
	q.push(V);
	bfs_visited[V] = true;
	while (!q.empty()) {
		int n = q.front();
		cout << n << " ";
		q.pop();
		for (int i = 0; i < graph[n].size(); i++) {
			int m = graph[n][i];
			if (!bfs_visited[m]) {
				q.push(m);
				bfs_visited[m] = true;
			}
		}

	}
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;


	// 그래프 저장
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i < N + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}


	dfs(V);
	cout << "\n";
	bfs(V);
	
	return 0;
}
