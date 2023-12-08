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

	vector<int> v(N + 1, 0);
	vector<int> s(N + 1, 0);
	int sum = 0;

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		sum += v[i];
		s[i] = sum;
		//cout << s[i] << " ";
	}

	for (int j = 0; j < M; j++) {
		int a, b;
		cin >> a >> b;
		cout << s[b] - s[a - 1] << "\n";
	}
	return 0;
}