#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;

    vector grid(m, vector<int>(n));
    for (auto &row : grid)
        for (int &i : row) 
        		cin >> i;

    auto check = [&](int x) -> bool {
        ranges::sort(grid, [&](const vector<int> &lhs, const vector<int> &rhs) {
            return (ranges::count_if(lhs, [&](int y) { return y < x; }) < ranges::count_if(rhs, [&](int y) { return y < x; }));
        });

        deque<bool> used(m);
        for (int i = 0; i < n; ++i) {
            bool ok = false;
            for (int j = 0; j < m; ++j) {
                if (grid[j][i] >= x) {
                    ok = true;
                    used[j] = true;
                    break;
                }
            }
            if (!ok) return false;
        }
        return ranges::count(used, true) <= n - 1;
    };

    int l, r, mid;
    for (l = 0, r = 1e9; l < r; check(mid) ? l = mid : r = mid - 1) {
        mid = (l + r + 1) / 2;
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