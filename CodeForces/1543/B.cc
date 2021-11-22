#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    i64 sum = accumulate(a.begin(), a.end(), i64(0));

    if (sum < n) {
        i64 p1 = sum, p0 = n - sum;
        cout << p1 * p0 << '\n';
    } else {
        if (sum % n == 0) {
            cout << 0 << '\n';
        } else {
            cout << (n - sum % n) * (sum % n) << '\n';
        }
    }
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