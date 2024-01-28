#include <iostream>
#include <vector>
using namespace std;

void findSmallestPrimeFactors(vector<bool>& is_prime, vector<int>& smallest_prime_factor, int max_val) {
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= max_val; i++) {
        if (is_prime[i]) {
            smallest_prime_factor[i] = i;
            for (int j = i * 2; j <= max_val; j += i) {
                is_prime[j] = false;
                if (smallest_prime_factor[j] == 0) smallest_prime_factor[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(nullptr);            // cin과 cout의 tie 해제

    const int MAX_VAL = 5000000;
    vector<bool> is_prime(MAX_VAL + 1, true);
    vector<int> smallest_prime_factor(MAX_VAL + 1, 0);

    findSmallestPrimeFactors(is_prime, smallest_prime_factor, MAX_VAL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        // 소인수분해 및 출력
        while (num > 1) {
            cout << smallest_prime_factor[num] << ' ';
            num /= smallest_prime_factor[num];
        }
        cout << '\n';
    }

    return 0;
}
