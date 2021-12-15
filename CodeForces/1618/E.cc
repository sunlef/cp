#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

void solve() {
    int n;
    cin >> n;

    vector<i64> b(n);
    for (i64 &bi : b) {
        cin >> bi;
    }

    i64 bsum = accumulate(b.begin(), b.end(), 0ll);
    i64 g = n * (n + 1) / 2;

    if (bsum % g != 0) {
        cout << "NO\n";
        return;
    }

    i64 asum = bsum / g;

    vector<i64> ans(n);
    for (int i = 0; i < n; ++i) {
        i64 d = (i == 0 ? b.back() : b[i - 1]) - b[i];
        d += asum;
        if (d % n != 0 || d / n < 1 || i64(d / n) > 1e9) {
        	cout << "NO\n";
        	return;
        }
        ans[i] = d / n;
    }

    cout << "YES\n";
    for (i64 ansi : ans) {
    	cout << ansi << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}