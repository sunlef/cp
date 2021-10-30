#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 1e5 + 7;

int nxt[SIZE], f[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        nxt[i] = -1;
        f[i] = i;
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            nxt[x] = y;
            f[y] = x;
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            nxt[x] = -1;
            f[y] = y;
        } else {
            int x;
            cin >> x;
            vector<int> ans;
            int u = x;
            while (u != f[u]) {
                u = f[f[u]];
            } 
            ans.push_back(u);
            int n = nxt[u];
            while (n != -1) {
                ans.push_back(n);
                n = nxt[n];
            }
            cout << ans.size() << ' ';
            for (auto &x : ans) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}