#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int N, L;
    scanf("%d %d", &N, &L);

    vector<int> arr(N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    deque<int> dq;

    for(int i = 0; i < N; i++) {
        while(!dq.empty() && dq.front() < i - L + 1) {
            dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] > arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        printf("%d ", arr[dq.front()]);
    }
    
    return 0;
}
