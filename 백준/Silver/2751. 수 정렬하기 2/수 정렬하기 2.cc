#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    // 작은 순서대로 temp 배열에 저장
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            ++i;
        } else {
            temp[k] = arr[j];
            ++j;
        }
        ++k;
    }

    // 왼쪽 부분 배열에 남아 있는 원소를 temp에 저장
    while (i <= mid) {
        temp[k] = arr[i];
        ++i;
        ++k;
    }

    // 오른쪽 부분 배열에 남아 있는 원소를 temp에 저장
    while (j <= right) {
        temp[k] = arr[j];
        ++j;
        ++k;
    }

    // 병합한 배열을 원래의 배열로 복사
    for (i = left, k = 0; i <= right; ++i, ++k) {
        arr[i] = temp[k];
    }
}

// 병합 정렬
void merge_sort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // 중간 지점을 계산한다.
        merge_sort(arr, left, mid); // 왼쪽 부분 배열 정렬
        merge_sort(arr, mid + 1, right); // 오른쪽 부분 배열 정렬
        merge(arr, left, mid, right); // 병합
    }
}

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    merge_sort(arr, 0, N - 1);
    
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << '\n';
    }
    
    return 0;
}
