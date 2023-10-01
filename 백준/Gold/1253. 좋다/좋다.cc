#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> v(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int first = 0; 
        int second = N - 1;
        while (first < second) {
            if (v[first] + v[second] == v[i]) {
                if ((first != i) && (second != i)) {  // index 기반으로 비교
                    ans++;
                    break;
                } else if (first == i) {
                    first++;
                } else if (second == i) {
                    second--;
                } else {  // 두 개가 같은 수이면서 합이 되는 경우 (예: [3,3,6])
                    first++;
                    second--;
                }
            } else if (v[first] + v[second] < v[i]) {
                first++;
            } else {
                second--;
            }
        }
    }
    cout << ans;
}