#include <iostream>
#include <vector>
#include <climits>

using namespace std;

static int N;
static vector<pair<int, int>> M;
static long D[502][502];

int execute(int s, int e);

int main() {
    cin >> N;
    M.resize(N + 1);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            D[i][j] = -1;
        }
    }

    for (int i = 1; i <= N; i++) {
        int y, x;
        cin >> y >> x;
        M[i] = make_pair(y, x);
    }

    cout << execute(1, N) << "\n";
    return 0;
}

int execute(int s, int e) {
    if (D[s][e] != -1) {
        return D[s][e];
    }
    if (s == e) {
        return 0;
    }
    if (s + 1 == e) {
        return M[s].first * M[s].second * M[e].second;
    }

    int result = INT_MAX;
    for (int i = s; i < e; i++) {
        int cost = execute(s, i) + execute(i + 1, e) + M[s].first * M[i].second * M[e].second;
        result = min(result, cost);
    }
    return D[s][e] = result;
}
