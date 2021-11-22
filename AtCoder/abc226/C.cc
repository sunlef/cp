#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> s;
    int n;
    cin >> n;
    vector<int> t(n);
    vector<vector<int>> g(n);

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            --x;
            g[i].push_back(x);
        }
    }

    queue<int> q;
    q.push(n - 1);
    s.insert(n - 1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : g[u]) {
            if (!s.count(v)) {
                s.insert(v);
                q.push(v);
            }
        }
    }

    int64_t ans = 0;
    for (auto &u : s) {
        ans += t[u];
    }
    cout << ans << '\n';

    return 0;
}