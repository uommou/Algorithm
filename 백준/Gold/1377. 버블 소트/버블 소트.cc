#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(make_pair(i, tmp)); // i 현 인덱스 저장
	}

	stable_sort(v.begin(), v.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
		return a.second < b.second; // second 기준으로 오름차순 정렬
		});
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].first - i) {
			ans = (ans < v[i].first - i) ? (v[i].first - i) : ans;
		}
	}

	cout << ans + 1 << '\n';
	return 0;
}