#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r, k;
    cin >> n >> l >> r >> k;

    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x >= l && x <= r) {
            a.push_back(x);
        }
    }

    if (a.size() == 0) {
        cout << "0\n";
        return;
    }

    ranges::sort(a);

    int ans = 0;
    int now = 0;

    for (auto &x : a) {
        if (now + x <= k) {
            ++ans;
            now += x;
        } else {
            break;
        }
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