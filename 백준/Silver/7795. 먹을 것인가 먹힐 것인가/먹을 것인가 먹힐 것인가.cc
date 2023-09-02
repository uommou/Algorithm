#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int ans = 0;
		//cout << T;
		int N, M;
		cin >> N >> M;
		//cout << N << M;
		vector <int> A(N, 0);
		vector <int> B(M, 0);
		for (int a = 0; a < N; a++) {
			cin >> A[a];
		}
		for (int b = 0; b < M; b++) {
			cin >> B[b];
		}

		sort(A.begin(), A.end(), greater<int>()); // 내림차순 정렬
		sort(B.begin(), B.end(), greater<int>());
		
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				if (A[a] > B[b]) {
					ans += M - b;
					break;
				}
				else
					continue;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
