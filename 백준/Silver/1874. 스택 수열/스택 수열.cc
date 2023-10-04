#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	stack<int> s;
	vector<char> v;
	int idx = 0; // stack에 들어간 최대정수
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (idx < tmp) {
			for (int j = idx + 1; j <= tmp; j++) {
				s.push(j); v.push_back('+');
			}
			//cout << "수열" << s.top() << '\n';
			s.pop();v.push_back('-');
			idx = tmp;
		}
		else {
			if (tmp == s.top()) {
				//cout << "수열" << s.top() << '\n';
				s.pop(); v.push_back('-');
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}