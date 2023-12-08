#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	map<int, string> find_pokemon;
	map<string, int> find_num;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		find_pokemon.insert({ i, temp });
		find_num.insert({ temp, i});
	}

	for (int j = 0; j < M; j++) {
		string q;
		cin >> q;
		if (isdigit(q[0])) { // 숫자가 입력되었을 경우
			cout << find_pokemon.find(stoi(q) - 1)->second << "\n";
		}
		else { // 문자가 입력되었을 경우
			cout << find_num.find(q)->second + 1 << "\n";
		}
	}
	return 0;
}