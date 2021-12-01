#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    ranges::sort(a);

    int cnt = 0;
    int CUTOFF = n / 2;

    auto ok = [&](int X, int Y) { return !ranges::binary_search(a, X % Y); };

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ok(a[j], a[i])) {
                cout << a[j] << ' ' << a[i] << '\n';
                ++cnt;
                if (cnt == CUTOFF) {
                    return;
                }
            }
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