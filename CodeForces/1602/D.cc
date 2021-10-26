#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    int a[300001] = {0}, b[300001] = {0};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    vector<int> dis(n + 1, INT_MAX);
    dis[n] = 0;
    int mn = n;

    queue<int> q;
    q.push(n);

    int pre[n + 1], from[n + 1];

    while (!q.empty() && mn > 0) {
        int u = q.front();
        q.pop();
        for (int i = u - a[u]; i < mn; ++i) {
            int v = i + b[i];
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
                pre[v] = i;
                from[v] = u;
            }
        }
        mn = min(mn, u - a[u]);
    }

    if (dis[0] == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << dis[0] << '\n';
        vector<int> ans(dis[0], 0);
        int now = 0;
        for (int i = dis[0] - 1; i >= 0; --i) {
            ans[i] = pre[now];
            now = from[now];
        }
        for (auto &x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}