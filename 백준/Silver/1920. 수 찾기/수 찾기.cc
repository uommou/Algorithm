#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(const vector<int>& sortedArray, int target) {
    int low = 0;
    int high = sortedArray.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (sortedArray[mid] == target) {
            return true;
        } else if (sortedArray[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sort(array.begin(), array.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;
        cout << binary_search(array, query) << '\n';
    }

    return 0;
}
