#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);
    for (auto &[x, y] : vec) {
        cin >> x >> y;
    }

    auto check = [&](int x) -> bool {
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            int A = vec[i].first, B = vec[i].second;
            if (x - cnt > A + 1) {
                continue;
            } else if (cnt > B) {
                continue;
            } else {
                ++cnt;
            }
        }

        return cnt >= x;
    };

    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << '\n';
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