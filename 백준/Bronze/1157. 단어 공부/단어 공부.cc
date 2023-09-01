#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	vector<int> alphabet(26, 0);
	string s;
	int m = 0; // 최대값
	int idx;
	int flag = 0; // true이면 ?

	cin >> s;
	for (int i = 0; i < size(s); i++) {
		alphabet[tolower(s[i]) - 'a']++;
	}
	for (int j = 0; j < 26; j++) {
		if (alphabet[j] > m) {
			m = alphabet[j];
			idx = j;
			flag = 0;
		}
		else if (alphabet[j] == m) {
			flag = 1;
		}
	}
	if (flag) {
		cout << '?';
	}
	else {
		cout << char('A' + idx);
	}
	return 0;
}