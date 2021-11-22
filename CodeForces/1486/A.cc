#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int64_t now = 0;
    int64_t cnt = 0;
    for (auto &x : a) {
        x += cnt;
        cnt = x - now;
        if (cnt < 0) {
            cout << "NO\n";
            return;
        }
        ++now;
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}