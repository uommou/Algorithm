#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int minVal = min(a, b);
    int gcd = 1; // 최대공약수 초기화
    for (int i = minVal; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
            break;
        }
    }

    int lcm = (a * b) / gcd; // 최소공배수 계산
    cout << gcd << '\n' << lcm << '\n';

    return 0;
}
