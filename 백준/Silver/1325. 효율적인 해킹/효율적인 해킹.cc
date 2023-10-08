#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[10001];
// vector<int> bfs_visited(10001, false);

int bfs(int V) {
	vector<int> bfs_visited(10001, false);
	int sum = 0;
	queue<int> q;
	q.push(V);
	bfs_visited[V] = true;
	while (!q.empty()) {
		int n = q.front();
		sum++;
		q.pop();
		for (int i = 0; i < graph[n].size(); i++) {
			int m = graph[n][i];
			if (!bfs_visited[m]) {
				q.push(m);
				bfs_visited[m] = true;
			}
		}

	}
	return sum;
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b; // b가 감염되면 a도 감염된다.
		graph[b].push_back(a); // b로 감염시킬 수 있는 컴퓨터를 저장
	}

	int max = 0;
	vector<int> ans;
	for (int i = 1; i < N + 1; i++) {
		int sum = bfs(i);
		//cout << i << " : " << sum << "\n";
		if (max < sum) {
			max = sum;
			//cout << i << "max updated";
			ans.clear();
			ans.push_back(i);
		}
		else if (max == sum) {
			ans.push_back(i);
			//cout << i << "max not updated";
		}
		else {
			continue;
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}