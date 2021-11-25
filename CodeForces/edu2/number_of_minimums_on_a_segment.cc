#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 100'000;
constexpr int seg_SIZE = 4 << __lg(SIZE);
constexpr int ls(int u) { return 2 * u; }
constexpr int rs(int u) { return 2 * u + 1; }

int n, m;
int info[SIZE];
pair<int, int> dat[seg_SIZE];  // {val, cnt}

pair<int, int> operator+(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    pair<int, int> res;
    if (lhs.first < rhs.first) {
        res.second = lhs.second;
    } else if (rhs.first < lhs.first) {
        res.second = rhs.second;
    } else {
        res.second = lhs.second + rhs.second;
    }
    res.first = min(lhs.first, rhs.first);
    return res;
}

void pull(int u) { dat[u] = dat[ls(u)] + dat[rs(u)]; }

void build(int u, int l, int r) {
    if (r - l == 1) {
        dat[u] = {info[l], 1};
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
        dat[u] = {val, 1};
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

pair<int, int> query(int u, int l, int r, int lhs, int rhs) {
    if (lhs <= l && r <= rhs) {
        return dat[u];
    } else {
        int mid = (l + r) / 2;
        pair<int, int> res = {INT_MAX, 0};
        if (lhs < mid) {
            res = res + query(ls(u), l, mid, lhs, rhs);
        }
        if (mid < rhs) {
            res = res + query(rs(u), mid, r, lhs, rhs);
        }
        return res;
    }
}
pair<int, int> query(int lhs, int rhs) { return query(1, 0, n, lhs, rhs); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }

    build(n);

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int val, pos;
            cin >> pos >> val;
            modify(pos, val);
        } else {
            int l, r;
            cin >> l >> r;
            pair<int, int> res = query(l, r);
            cout << res.first << ' ' << res.second << '\n';
        }
    }

    return 0;
}