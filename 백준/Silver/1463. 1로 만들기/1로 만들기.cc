#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, INT_MAX); // INT_MAX로 초기화
    dp[1] = 0; // 초기 조건

    for (int i = 2; i <= N; i++) {
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    cout << dp[N] << endl;
    return 0;
}
