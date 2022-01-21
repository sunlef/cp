#include <bits/stdc++.h>
using namespace std;

struct fenwick {
    int n;
    std::vector<int> info;

    fenwick(int n) : n(n + 1), info(n + 1) {}
    void add(int pos, int val) {
        for (; pos < n; pos += pos & -pos) info[pos] += val;
    }
    int query(int pos) {
        int res = 0;
        for (; pos; pos -= pos & -pos) res += info[pos];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<tuple<int, int, int, int>> op;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        op.push_back({x, y, 0, 0});
    }

    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        op.push_back({x, y, 1, i});
    }

    vector<int> a(op.size()), b(op.size());
    for (int i = 0; i < int(op.size()); ++i) {
        a[i] = get<0>(op[i]);
        b[i] = get<1>(op[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (auto &[x, y, z, i] : op) {
        x = lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
        y = lower_bound(b.begin(), b.end(), y) - b.begin() + 1;
    }

    sort(op.begin(), op.end());

    fenwick fen(b.size() + 1);

    vector<int> ans(Q);

    for (auto [x, y, z, i] : op) {
        // cout << x << ' ' << y << ' ' << z << ' ' << i << '\n';
        if (z == 0) {
            fen.add(y, 1);
        } else {
            ans[i] = fen.query(y);
        }
    }

    for (int i : ans) {
        cout << i << '\n';
    }

    return 0;
}