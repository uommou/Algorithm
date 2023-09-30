#include <iostream>
#include <vector>


using namespace std;

int main() {
	int N;
	cin >> N;
	int start = 1; int end = 1;
	int sum = 1;
	int ans = 1; // 자기자신
	while (end != N) {
		if (sum == N) {
			//cout << end;
			ans++;
			end++;
			sum += end;
		}
		else if (sum < N) {
			end++;
			sum += end;
		}
		else if (sum > N) {
			sum -= start;
			start++;
		}
	}
	cout << ans;
}