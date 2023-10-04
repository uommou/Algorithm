#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string N;
	cin >> N;
	
	for (int i = 0; i < N.size(); i++) {
		int m = 0;
		int idx = 0;
		for (int j = i; j < N.size(); j++) {
			if (m <= N[j]) {
				m = N[j]; // 최댓값 업데이트
				idx = j;
			}
		}
		if (idx) {
			swap(N[i], N[idx]);
		}
		
	}
	
	cout << N;

	return 0;
}