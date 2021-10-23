
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    auto d = a;
    for (int i = 1; i < n; ++i) {
        d[i] = a[i] - a[i - 1];
    }
    d.push_back(0 - *a.rbegin());

    for (int i = 0; i < 3; ++i) {
        if (d[i] < 0) {
            cout << "No\n";
            return;
        }
    }

    int64_t cur = 0;

    for (int i = 0; i <= n; ++i) {
        auto &x = d[i];
        if (x > 0) {
            cur += x;
        }

        if (i + 3 <= n && d[i + 3] < 0) {
            cur += d[i + 3];
        }

        if (cur < 0) {
            cout << "No\n";
            return;
        }
    }

    if (cur == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        cout << "Case #" << TwT << ": ";
        solve();
    }

    return 0;
}