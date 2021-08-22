#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, M;
    cin >> L >> M;
    vector<int> a(L+1, 1);

    for(int i = 1; i <= M; ++i) {
        int st, b;
        cin >> st >> b;
        for(int j = st; j <= b; ++j) {
            a[j] = 0;
        }
    }

    int cnt = 0;

    for(int i = 0; i <= L; ++i)
        cnt += a[i];
    
    cout << cnt << '\n';

    return 0;
}
