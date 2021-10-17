#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto &x : a) {
        cin >> x;
    }

    vector<int> d;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            if (a[i] == a[j]) {
                continue;
            } else {
                d.push_back(abs(a[i] - a[j]));
            }
        }
    }

    if (d.size() == 0) {
        cout << -1 << '\n';
    } else if (d.size() == 1) {
        cout << d[0] << '\n';
    } else {
        int res = gcd(d[0], d[1]);
        for (int i = 2; i < d.size(); ++i) {
            res = gcd(res, d[i]);
        }
        cout << res << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}