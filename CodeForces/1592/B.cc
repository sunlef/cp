#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    auto b = a;
    sort(b.begin(), b.end());

    int l = n - x + 1, r = x;
    for (int i = 1; i <= n; ++i) {
        if (i >= l && i <= r) {
            if (a[i] != b[i]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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