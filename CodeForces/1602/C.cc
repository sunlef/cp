#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto &x : a) {
        cin >> x;
    }

    if (count(a.begin(), a.end(), 0) == n) {
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    vector<int> b(32);
    for (int i = 0; i <= 31; ++i) {
        for (auto &x : a) {
            if ((x >> i) & 1) {
                ++b[i];
            }
        }
    }

    int res = 0;
    for (int i = 0; i < 32; ++i) {
        res = gcd(res, b[i]);
    }

    vector<int> ans;
    for (int i = 1; i <= sqrt(res); ++i) {
        if (res % i == 0) {
            ans.push_back(i);
            if (res / i != i) {
                ans.push_back(res / i);
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (auto &x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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