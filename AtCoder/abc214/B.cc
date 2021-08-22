#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    int cnt = 0;
    for(int i = 0; i <= N; ++i)
        for(int j = 0; j + i <= N; ++j){
            for(int k = 0; j+i+k <= N; ++k)
                if((long long)(i)*j*k <= T) ++cnt;
        
        }
    cout << cnt << endl;
    
    return 0;
}
