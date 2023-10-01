#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int P; int S;
	cin >> S >> P;
	string DNA;
	cin >> DNA;
	vector<int> check_ACGT(4, 0); // 기준
	vector<int> input_ACGT(4, 0);
	for (int i = 0; i < 4; i++) {
		cin >> check_ACGT[i];
	}
	int start = 0; int end = P - 1;
	int ans = 0;

	// 시작
	for (int i = 0; i < P; i++) {
		if (DNA[i] == 'A') input_ACGT[0]++;
		else if (DNA[i] == 'C') input_ACGT[1]++;
		else if (DNA[i] == 'G') input_ACGT[2]++;
		else if (DNA[i] == 'T') input_ACGT[3]++;
	}

	while (end < S) {
		if ((check_ACGT[0] <= input_ACGT[0]) && (check_ACGT[1] <= input_ACGT[1]) && (check_ACGT[2] <= input_ACGT[2]) && (check_ACGT[3] <= input_ACGT[3])) {
			ans++;
		}
		
		if (DNA[start] == 'A') input_ACGT[0]--;
		else if (DNA[start] == 'C') input_ACGT[1]--;
		else if (DNA[start] == 'G') input_ACGT[2]--;
		else if (DNA[start] == 'T') input_ACGT[3]--;
		start++; // start 제거

		end++; // end 추가
		if (DNA[end] == 'A') input_ACGT[0]++;
		else if (DNA[end] == 'C') input_ACGT[1]++;
		else if (DNA[end] == 'G') input_ACGT[2]++;
		else if (DNA[end] == 'T') input_ACGT[3]++;

	}
	cout << ans;
}