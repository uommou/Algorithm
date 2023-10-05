#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	
	queue<int> q;

	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}
	int tmp;
	while (!q.empty()) {
		// 제거
		tmp = q.front();
		q.pop();
		if (q.empty()) {
			cout << tmp;
			break;
		}
		// 옮기기
		q.push(q.front());
		q.pop();
	}
	return 0;
}
