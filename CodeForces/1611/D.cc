#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> b(n), p(n);
    for (int &x : b) {
        cin >> x;
        --x;
    }
    for (int &x : p) {
        cin >> x;
        --x;
    }

    vector<int> idx(n), ans(n);
    for (int i = 0; i < n; ++i) {
        idx[p[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        if (b[i] != i) {
            ans[i] = idx[i] - idx[b[i]];
            if (ans[i] < 0) {
                cout << "-1\n";
                return;
            }
        }
    }

    for (int &x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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