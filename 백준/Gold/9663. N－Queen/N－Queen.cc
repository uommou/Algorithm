#include <iostream>
#include <vector>
using namespace std;

int N, answer = 0;
vector<int> row;

bool isPromising(int x) {
    for (int i = 0; i < x; i++) {
        if (row[i] == row[x] || abs(row[x] - row[i]) == abs(x - i)) {
            return false;
        }
    }
    return true;
}

void nQueen(int x) {
    if (x == N) {
        answer++;
        return;
    }
    for (int i = 0; i < N; i++) {
        row[x] = i;
        if (isPromising(x)) {
            nQueen(x + 1);
        }
    }
}

int main() {
    cin >> N;
    row.resize(N);
    nQueen(0);
    cout << answer << endl;
    return 0;
}
