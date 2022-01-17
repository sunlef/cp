#include <bits/stdc++.h>
using namespace std;

struct dsu {
    private:
    int n;
    std::vector<int> f, sz;

    public:
    dsu(int n) : n(n), f(n + 1), sz(n + 1, 1) { std::iota(f.begin(), f.end(), 0); }
    int big_brother(int u) {
        if (u > n) return -1;
        while (u != f[u]) u = f[u] = f[f[u]];
        return u;
    }
    bool same(int u, int v) {
        int a = big_brother(u), b = big_brother(v);
        if (a == b && a != -1)
            return true;
        else
            return false;
    }
    bool merge(int u, int v) {
        if (u > n || v > n) return false;
        int a = big_brother(u), b = big_brother(v);
        if (a == b) return false;
        if (sz[a] > sz[b])
            f[b] = a, sz[a] += sz[b];
        else
            f[a] = b, sz[b] += sz[a];
        return true;
    }
    int size(int u) { return sz[big_brother(u)]; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    dsu s(3 * N);
    //把x定义为同类，x + N定义为猎物，x + 2 * N定义为天敌

    int ans = 0;

    while (K--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (x > N || y > N) {
            ++ans;
        } else if (op == 1) {
            if (s.same(x + N, y) || s.same(x + 2 * N, y)) {  //x是y的猎物 或 x是y的天敌
                ++ans;
            } else {
                s.merge(x, y);                  // x的同类是y的同类
                s.merge(x + N, y + N);          // x的猎物是y的猎物
                s.merge(x + 2 * N, y + 2 * N);  // x的天敌是y的天敌
            }
        } else {
            if (s.same(x, y) || s.same(x + 2 * N, y)) {  // x与y是同类 或 x是y的猎物
                ++ans;
            } else {
                s.merge(x, y + 2 * N);      // x的同类是y的天敌
                s.merge(x + N, y);          // x的猎物是y的同类
                s.merge(x + 2 * N, y + N);  // x的天敌是y的猎物
            }
        }
    }

    cout << ans << '\n';
    return 0;
}