#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    int cross_product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (cross_product > 0) {
        cout << 1;  // 반시계 방향
    } else if (cross_product < 0) {
        cout << -1;  // 시계 방향
    } else {
        cout << 0;  // 일직선
    }

    return 0;
}