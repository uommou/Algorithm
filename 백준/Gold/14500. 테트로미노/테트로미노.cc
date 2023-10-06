#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	int dx[19][4] = {
		{0, 1, 0, 1}, 
		{0, 1, 2, 3}, {0, 0, 0, 0}, 
		{0, 0, 1, 1}, {0, 0, -1, -1}, {0, 1, 1, 2}, {0, 1, 1, 2},
		{0, 1, 2, 1}, {0, 1, 1, 2}, {0, 1, 1, 1}, {0, 0, 0, 1},
		{0, 0, 0, 1}, {0, 0, 0, -1}, {0, 0, 0, 1}, {0, 1, 1, 1}, {0, 1, 2, 2}, {0, 1, 2, 2}, {0, 0, 1, 2}, {0, 0, 1, 2}
	};

	int dy[19][4] = {
		{0, 0, 1, 1}, 
		{0, 0, 0, 0}, {0, 1, 2, 3}, 
		{0, 1, 1, 2}, {0, 1, 1, 2}, {0, 0, -1, -1}, {0, 0, 1, 1},
		{0, 0, 0, 1}, {0, -1, 0, 0}, {0, -1, 0, 1}, {0, 1, 2, 1},
		{0, 1, 2, 2}, {0, 1, 2, 2}, {0, 1, 2, 0}, {0, 0, 1, 2}, {0, 0, 0, -1}, {0, 0, 0, 1}, {0, 1, 1, 1}, {0, 1, 0, 0}
	};

	int ans = 0;


	for (int t = 0; t < 19; t++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				int sum = 0;
				for (int b = 0; b < 4; b++) {
					int cur_y = i + dy[t][b];
					int cur_x = j + dx[t][b];
					if ((cur_x < 0 || cur_x >= M) || (cur_y < 0 || cur_y >= N)) {
						break;
					}
					else {
						sum += v[cur_y][cur_x];
					}
				}
				
				ans = (sum > ans) ? sum : ans;
			}
		}
	}

	cout << ans;
	return 0;
}