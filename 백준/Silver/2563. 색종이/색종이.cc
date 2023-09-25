#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


int main() {
	
	vector<vector<int>> white(100, vector<int> (100, 0)); // 0으로 초기화

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		
		// fill black
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				white[k][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (white[i][j] == 1) {
				ans++;
			}
		}
	}

	cout << ans;
}