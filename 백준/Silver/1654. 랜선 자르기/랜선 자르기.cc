#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_make_cables(const vector<long long>& cableLengths, int target, long long length) {
    long long count = 0;
    for (long long cable : cableLengths) {
        count += cable / length;
        if (count >= target) {
            return true;
        }
    }
    return count >= target;
}

long long binary_search_max_length(const vector<long long>& cableLengths, int target) {
    long long low = 1;
    long long high = *max_element(cableLengths.begin(), cableLengths.end());
    long long maxLength = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (can_make_cables(cableLengths, target, mid)) {
            maxLength = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return maxLength;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;
    vector<long long> cableLengths(k);
    for (int i = 0; i < k; ++i) {
        cin >> cableLengths[i];
    }

    long long maxLength = binary_search_max_length(cableLengths, n);
    cout << maxLength << endl;

    return 0;
}
