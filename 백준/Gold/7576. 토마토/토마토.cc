#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> v(1001, vector<int>(1001, 0));


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> M >> N;
	vector<vector<int>> v(N, vector<int>(M, 0));
	queue<pair<int, int>> q;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	int day =-1;

	while (!q.empty()) {
		
		int s = q.size();
		//cout << s << "\n";
		
		for (int i = 0; i < s; i++) { // 각 토마토에 대해
			pair<int, int> tomato = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) { // 상하좌우 방향 탐색
				int ty = tomato.first + dy[j];
				int tx = tomato.second + dx[j];
				if (ty >= 0 && ty < N && tx >=0 && tx < M) { // 범위체크
					if (v[ty][tx] == 0) {
						//cout << ty << tx << " : " << v[ty][tx] << " ";
						v[ty][tx] = 1; // 익은 토마토로 바꾸기
						q.push(make_pair(ty, tx));
						
					}
				}
			}
		}
		day++;
	}

	// 모든 토마토가 익었는지 확인
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << day;
	
	return 0;
}