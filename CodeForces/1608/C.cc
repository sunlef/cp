#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    auto A = a, B = b;
    ranges::sort(A), ranges::sort(B);
    for (int &x : a) x = int(ranges::lower_bound(A, x) - A.begin());
    for (int &x : b) x = int(ranges::lower_bound(B, x) - B.begin());

    vector<int> idx_a(n);
    for (int i = 0; i < n; ++i) idx_a[a[i]] = i;

    string ans(n, '0');
    int MIN = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        int idx = idx_a[i];
        ans[idx] = '1';
        MIN = std::min(MIN, b[idx]);
        if (MIN == i) break;
    }

    cout << ans << '\n';
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