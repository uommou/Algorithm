#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; int L;
	cin >> N >> L;

	vector<long long> v(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	
	deque<long long> dq; // 선입선출 덱을 이용하여 덱 안의 최소값을 구한다.

	for (int i = 1; i <= N; i++) {
		// 덱: back으로 들어와서 front로 나간다(제거된다)
		// 범위를 벗어나는 수 제거
		while (!dq.empty() && dq.front() < i - L + 1) {
			dq.pop_front();
		}
		// 추가될 수가 back 보다 작으면 back 제거 -> front부터 오름차순으로 정렬된다.
		while (!dq.empty() && v[dq.back()] > v[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
		cout << v[dq.front()] << " ";
	}
}
