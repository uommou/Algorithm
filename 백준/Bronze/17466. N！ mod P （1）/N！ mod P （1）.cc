#include <iostream>
using namespace std;

int main() {
    long long N, P;
    cin >> N >> P;

    long long factorial = 1;
    for (long long i = 1; i <= N; i++) {
        factorial = (factorial * i) % P;
    }

    cout << factorial % P << endl;
    return 0;
}
