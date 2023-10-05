#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> v(N, 0);
	vector<int> r(N, -1);
	stack<int> s;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < N; i++) {
		// 1. 스택이 채워져 있고 v[i] > v[top]인 경우 pop한 인덱스를 이용하여 정답 수열에 오큰수를 저장한다.
		// pop은 조건을 만족하는 동안 계속 반복한다.
		while (!s.empty() && (v[i] > v[s.top()])) {
			r[s.top()] = v[i];
			s.pop();
		}
		// 2. 현재 인덱스를 스택에 push하고 다음 인덱스로 넘어간다.
		s.push(i);
	}
	// 3. 수열 길이만큼 반복한 다음 현재 스택에 남아있는 인덱스에 -1을 저장한다.
	// r을 -1로 초기화 했으므로 pass
	for (int i = 0; i < N; i++) {
		cout << r[i] << " ";
	}
	return 0;
}
