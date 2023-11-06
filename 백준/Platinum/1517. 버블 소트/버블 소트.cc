#include <iostream>
#include <vector>
using namespace std;

long long swap_count = 0; // 스왑 횟수를 저장할 전역 변수

void merge(vector<int> &arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    vector<int> temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // 왼쪽 부분 배열의 요소가 오른쪽 요소보다 클 때 스왑 발생
            temp[k++] = arr[j++];
            swap_count += (mid - i + 1); // 남아 있는 왼쪽 부분 배열의 요소 수만큼 스왑 횟수 증가
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

void merge_sort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);

    cout << swap_count << endl; // 스왑 횟수 출력

    return 0;
}
