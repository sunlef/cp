#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(2 * n + 1), d(2 * n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        d[a[i]] = i;
    }
    for (int i = 1; i <= 2 * n; i += 2) {
        int pos = c[i];
        
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