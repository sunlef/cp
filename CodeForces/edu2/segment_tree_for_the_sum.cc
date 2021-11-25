#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 100'000;
constexpr int seg_SIZE = 4 << __lg(SIZE);
constexpr int ls(int u) { return 2 * u; }
constexpr int rs(int u) { return 2 * u + 1; }

int n;

int64_t dat[seg_SIZE], info[SIZE];

void pull(int u) { dat[u] = dat[ls(u)] + dat[rs(u)]; }

void build(int u, int l, int r) {
    if (r - l == 1) {
        dat[u] = info[l];
    } else {
        int mid = (l + r) / 2;
        build(ls(u), l, mid);
        build(rs(u), mid, r);
        pull(u);
    }
}
void build(int n) { build(1, 0, n); }

void modify(int u, int l, int r, int pos, int val) {
    if (r - l == 1) {
        dat[u] = val;
    } else {
        int mid = (l + r) / 2;
        if (pos < mid) {
            modify(ls(u), l, mid, pos, val);
        } else {
            modify(rs(u), mid, r, pos, val);
        }
        pull(u);
    }
}
void modify(int pos, int val) { modify(1, 0, n, pos, val); }

int64_t query(int u, int l, int r, int lhs, int rhs) {
    if (lhs <= l && r <= rhs) {
        return dat[u];
    } else {
        int mid = (l + r) / 2;
        int64_t res = 0;
        if (lhs < mid) {
            res += query(ls(u), l, mid, lhs, rhs);
        }
        if (mid < rhs) {
            res += query(rs(u), mid, r, lhs, rhs);
        }
        return res;
    }
}
int64_t query(int lhs, int rhs) { return query(1, 0, n, lhs, rhs); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }

    build(n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos, val;
            cin >> pos >> val;
            modify(pos, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << '\n';
        }
    }

    return 0;
}