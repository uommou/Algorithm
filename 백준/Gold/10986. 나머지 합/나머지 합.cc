#include <iostream>
#include <vector>


using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long N, M;
	cin >> N >> M;

	vector<long long> v(N + 1, 0);
	vector<long long> s(N + 1, 0);
	vector<long long> q(M, 0); q[0] = 1;
	long long sum = 0;

	for (long long i = 1; i < N + 1; i++) {
		cin >> v[i];
		sum += v[i];
		s[i] = sum % M;
		q[s[i]]++;
	}

	long long ans = 0;
	
	for (long long i = 0; i < M; i++) {
		long long t = q[i];
		ans += t * (t - 1) / 2;
	}
	cout << ans;

	return 0;
}