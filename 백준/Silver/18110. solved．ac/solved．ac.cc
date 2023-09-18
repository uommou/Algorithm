#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>

using namespace std;


int main() {
	
	int ans = 0;
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	vector<int> opinions(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> opinions[i];
	}
	sort(opinions.begin(), opinions.end());
	int minus = round(n * 0.15); // 반올림

	float sum = 0;
	for (int i = minus; i < n - minus; i++) {
		sum += opinions[i];
	}
	ans = round(sum / (n - minus * 2));
	cout << ans;
	return 0;
}