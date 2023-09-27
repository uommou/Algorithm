#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> chart(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> sumchart(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		int sum = 0;

		for (int j = 1; j <= N; j++) {
			cin >> chart[i][j];
			sum += chart[i][j];
			sumchart[i][j] = sum + sumchart[i - 1][j];
		}
	}

	int x1, x2, y1, y2;
	
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sumchart[x2][y2] + sumchart[x1 - 1][y1 - 1] - sumchart[x2][y1 - 1] - sumchart[x1 - 1][y2] << "\n";
	}
	return 0;
}