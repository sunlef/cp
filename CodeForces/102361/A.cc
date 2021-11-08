#include <bits/stdc++.h>
using namespace std;

using u64 = uint64_t;
using um = unordered_map<u64, int>;

struct Node {
    int x, y;
};

constexpr u64 line(const Node& lhs, const Node& rhs) {
    int dx = lhs.x - rhs.x;
    int dy = lhs.y - rhs.y;
    int t = gcd(dx, dy);
    dx /= t, dy /= t;
    return u64(114514) + u64(1919810) * dx + u64(23313313333) * dy;
}

constexpr u64 inv_line(const Node& lhs, const Node& rhs) {
    int dy = lhs.x - rhs.x;
    int dx = rhs.y - lhs.y;
    int t = gcd(dx, dy);
    dx /= t, dy /= t;
    return u64(114514) + u64(1919810) * dx + u64(23313313333) * dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<Node> p(n), w(q);
    for (auto& [x, y] : p) {
        cin >> x >> y;
    }
    for (auto& [x, y] : w) {
        cin >> x >> y;
    }

    vector<int> ans(q);

    // 查询点为直角
    for (int i = 0; i < q; ++i) {
        um mp;
        for (int j = 0; j < n; ++j) {
            ++mp[line(w[i], p[j])];
        }
        for (int j = 0; j < n; ++j) {
            ans[i] += mp[inv_line(w[i], p[j])] + mp[inv_line(p[j], w[i])];
        }
        ans[i] /= 2;
    }

    // 查询角为非直角
    for (int i = 0; i < n; ++i) {
        um mp;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                ++mp[line(p[i], p[j])];
            }
        }
        for (int j = 0; j < q; ++j) {
            ans[j] += mp[inv_line(p[i], w[j])] + mp[inv_line(w[j], p[i])];
        }
    }

    for (auto& x : ans) {
        cout << x << '\n';
    }

    return 0;
}