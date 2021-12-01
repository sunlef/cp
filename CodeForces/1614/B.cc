#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int64_t, int>> vec(n);
    for (int i = 0; auto &[x, y] : vec) {
        cin >> x;
        y = i++;
    }
    stable_sort(vec.rbegin(), vec.rend());

    vector<int64_t> ans(n);
    int pos = 1;
    for (auto &[x, y] : vec) {
        ans[y] = pos;
        if (pos > 0) {
            pos *= -1;
        } else {
            pos = -pos + 1;
        }
    }

    int64_t dist = 0;
    for (auto &[x, y] : vec) {
        dist += 2 * x * abs(ans[y]); 
    }

    cout << dist << '\n';
    cout << "0 ";
    for (auto &x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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