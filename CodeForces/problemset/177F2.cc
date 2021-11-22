#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, t;
    cin >> n >> k >> t;

    vector e(n, vector<int>(n));
    while (k--) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        e[u][v] = w;
    }

    int l = 0, r = 1000 * n;
    while (l < r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        vector<int> match(n);
        function<void(int, int)> dfs = [&](int pos, int sum) {
            if (pos == n) {
                ++cnt;
                return;
            }
            dfs(pos + 1, sum);
            for (int i = 0; i < n; ++i) {
                if (cnt >= t) {
                    return;
                }
                if (!match[i] && e[pos][i] && sum + e[pos][i] <= mid) {
                    match[i] = 1;
                    dfs(pos + 1, sum + e[pos][i]);
                    match[i] = 0;
                }
            }
        };
        dfs(0, 0);
        if (cnt >= t) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
    return 0;
}