#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lower_bound(const vector<int>& array, int target) {
    int low = 0, high = array.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (array[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int upper_bound(const vector<int>& array, int target) {
    int low = 0, high = array.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (array[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int count_cards(const vector<int>& cards, int number) {
    int lower = lower_bound(cards, number);
    int upper = upper_bound(cards, number);
    return upper - lower;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());

    cin >> m;
    vector<int> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i];
    }

    for (int number : queries) {
        cout << count_cards(cards, number) << " ";
    }

    return 0;
}