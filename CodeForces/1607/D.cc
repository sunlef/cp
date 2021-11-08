#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> B, R;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            B.push_back(a[i]);
        } else {
            R.push_back(a[i]);
        }
    }

    ranges::sort(B);
    ranges::sort(R, greater<int>());

    for (int i = 0; i < B.size(); ++i) {
        if (B[i] < i + 1) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < R.size(); ++i) {
        if (R[i] > n - i) {
            cout << "NO\n";
            return;
        }
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