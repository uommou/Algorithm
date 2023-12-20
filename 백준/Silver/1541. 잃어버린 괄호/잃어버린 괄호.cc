#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    // 숫자와 부호를 분리하기
    vector<int> numbers;
    vector<char> ops;
    stringstream ss;
    for (char c : s) {
        if (isdigit(c)) {
            ss << c;
        } else {
            numbers.push_back(stoi(ss.str()));
            ss.str("");
            ops.push_back(c);
        }
    }
    numbers.push_back(stoi(ss.str())); // 마지막 숫자 추가

    // 계산
    int result = numbers[0];
    bool minus = false;
    for (size_t i = 0; i < ops.size(); i++) {
        if (ops[i] == '-') {
            minus = true;
        }
        if (minus) {
            result -= numbers[i + 1];
        } else {
            result += numbers[i + 1];
        }
    }

    cout << result << endl;
    return 0;
}
