#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<vector<int>> DP(1001, vector<int>(1001, 0));

void LCS(string A, string B) {
    for (int i = 1; i <= A.size(); i++) {
        for (int j = 1; j <= B.size(); j++) {
            if (A[i-1] == B[j-1]) {
                DP[i][j] = DP[i-1][j-1] + 1;
            } else {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
}

string getLCS(string A, string B) {
    int i = A.size();
    int j = B.size();
    string lcs;

    while (i > 0 && j > 0) {
        if (A[i-1] == B[j-1]) {
            lcs.push_back(A[i-1]);
            i--; j--;
        } else if (DP[i-1][j] >= DP[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string A, B;
    cin >> A >> B;

    LCS(A, B);
    string lcs = getLCS(A, B);
    cout << lcs.size() << "\n" << lcs << "\n";
    return 0;
}
