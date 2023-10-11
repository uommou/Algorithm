#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> v(10001, 0);
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        v[tmp]++;
    }
    for(int i=0; i<10001; i++){
        for(int j=0; j<v[i]; j++){
            cout << i << "\n";
        }
    }
}