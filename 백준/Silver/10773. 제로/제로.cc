#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;


int main() {
	int K;
	cin >> K;

	stack<int> s;
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		if (temp) {
			s.push(temp);
		}
		else {
			s.pop();
		}
		
	}

	int sum = 0;
	while(!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
	return 0;
}