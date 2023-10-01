#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; int M;
	cin >> N >> M;
	vector<int> ingredients(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> ingredients[i];
	}
	sort(ingredients.begin(), ingredients.end());

	int first = 0; int second = N - 1;
	int ans = 0;
	while (first != second) {
		if (ingredients[first] + ingredients[second] == M) {
			ans++;
			first++;
		}
		else if (ingredients[first] + ingredients[second] < M) {
			first++;
		}
		else if (ingredients[first] + ingredients[second] > M) {
			second--;
		}
	}
	cout << ans;
}