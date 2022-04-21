#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        ++cnt[x];
    }

    for (int i = 0; i <= n; ++i) {
        if (cnt[i] >= 3) {
            cout << i << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int QvQ = 1; QvQ <= T; ++QvQ) {
        solve();
    }

    return 0;
}