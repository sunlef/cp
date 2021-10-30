#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<int> unused;
    for (int i = 0; i < n; ++i) {
        unused.insert(i);
    }

    vector<set<int>> e(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].insert(v);
        e[v].insert(u);
    }

    int ans = n - 1;

    auto bfs = [&](int s) {
        queue<int> q;
        q.push(s);
        unused.erase(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto it = unused.begin(); it != unused.end();) {
                auto nxt = next(it);
                if (int v = *it; !e[u].count(v)) {
                    --ans;
                    q.push(v);
                    unused.erase(it);
                }
                it = nxt;
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (unused.count(i)) {
            bfs(i);
        }
    }

    cout << ans << '\n';
    return 0;
}