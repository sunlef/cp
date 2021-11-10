#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> c(n), w(n), cnt(n);

    for (auto &x : c) {
        cin >> x;
        --x;
        ++cnt[x];
    }
    for (auto &x : w) {
        cin >> x;
    }

    vector g(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }

    int sum = 0;
    vector<int> cid(n, -1);
    for (int i = 0; i < n; ++i) {
        if (cnt[i] > 1) {
            cid[i] = sum++;
        }
    }

    auto getb = [&](int u) -> int { return 1 << cid[c[u]]; };
    auto getw = [&](int u) -> int { return w[c[u]]; };
    auto update = [](int &before, const int &after) -> void { before = max(before, after); };

    vector<map<int, int>> dp(n);

    if (cid[c[0]] != -1) {
        dp[0][getb(0)] = getw(0);
    } else {
        dp[0][0] = getw(0);
    }

    for (int u = 0; u < n; ++u) {
        for (auto &[now, val] : dp[u]) {
            for (int v : g[u]) {
                if (cid[c[v]] == -1) {
                    update(dp[v][now], dp[u][now] + getw(v));
                } else {
                    if ((now >> cid[c[v]]) & 1) {
                        update(dp[v][now], dp[u][now]);
                    } else {
                        update(dp[v][(now | getb(v))], dp[u][now] + getw(v));
                    }
                }
            }
        }
    }

    for (int u = 0; u < n; ++u) {
        int ans = 0;
        for (auto &[now, val] : dp[u]) {
            update(ans, val);
        }
        cout << ans << '\n';
    }

    return 0;
}