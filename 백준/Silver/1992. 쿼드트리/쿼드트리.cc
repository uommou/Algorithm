#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> imageMatrix; // 'data'에서 'imageMatrix'로 이름 변경

string quadTree(int y, int x, int size) {
    char init = imageMatrix[y][x];
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (imageMatrix[i][j] != init) {
                int newSize = size / 2;
                return "(" 
                    + quadTree(y, x, newSize)
                    + quadTree(y, x + newSize, newSize)
                    + quadTree(y + newSize, x, newSize)
                    + quadTree(y + newSize, x + newSize, newSize)
                    + ")";
            }
        }
    }
    return string(1, init);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    imageMatrix.resize(n, vector<char>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> imageMatrix[i][j];
        }
    }

    cout << quadTree(0, 0, n);

    return 0;
}
