#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    map<int, int> cnt;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int x;
        cin >> x;
        cout << cnt[x] << '\n';
    }

    return 0;
}