#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	int N;
	cin >> N;

	int ans = 0;
	int sum = 0;
	vector<int> t(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}
	sort(t.begin(), t.end());//오름차순

	for (int i = 0; i < N; i++) {

		ans += t[i];
		sum += ans;
	}

	cout << sum;

	return 0;
}