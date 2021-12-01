#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    vector<int> dist(n, INT_MAX);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        --x;
        dist[x] = 0;
        q.push(x);
    }

    vector adj(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int &v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    bool ok = false;
    int ans = 0;
    function<void(int, int, int)> dfs = [&](int u, int fa, int step) -> void {
        if (step >= dist[u]) {
            ++ans;
            return;
        } else if (adj[u].size() == 1 && u != 0) {
            ok = true;
        } else {
            for (int &v : adj[u]) {
                if (fa != v) {
                    dfs(v, u, step + 1);
                }
            }
        }
    };
    dfs(0, 0, 0);

    cout << (ok ? -1 : ans) << '\n';
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