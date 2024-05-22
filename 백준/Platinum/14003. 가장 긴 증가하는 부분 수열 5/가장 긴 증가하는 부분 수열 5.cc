#include <iostream>
#include <vector>

using namespace std;

static int N, maxLength;
static vector<int> B(1000001, 0);
static vector<int> A(1000001, 0);
static vector<int> D(1000001, 0);
static vector<int> ans(1000001, 0);
int binarySearch(int i, int r, int now);

int main() {
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> A[i];
    }
    
    int index;
    B[++maxLength] = A[1];
    D[1] = 1;
    
    for (int i=2; i<=N; i++){
        if (B[maxLength] < A[i]) {
            B[++maxLength] = A[i];
            D[i] = maxLength;
        }
        else {
            index = binarySearch(1, maxLength, A[i]);
            B[index] = A[i];
            D[i]=index;
        }
    }
    
    cout << maxLength << "\n";
    index=maxLength;
    int x = B[maxLength] + 1;
    
    for (int i=N; i>= 1; i--){
        if (D[i]==index&&A[i]<x){
            ans[index] = A[i];
            x=A[i];
            index--;
        }
    }
    for (int i=1; i<=maxLength; i++){
        cout << ans[i] << " ";
    }
}

int binarySearch(int l, int r, int now){
    int mid;
    while(l<r){
        mid = (l+r)/2;
        if (B[mid]<now){
            l=mid+1;
        }
        else {
            r = mid;
        }
    }
    return l;
}
