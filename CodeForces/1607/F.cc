#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &row : grid) {
        cin >> row;
    }

    int dx[] = {0, -1, 0, 1};
    int dy[] = {1, 0, -1, 0};

    auto get = [&](int h, int w) -> int { return h * m + w; };
    auto check = [&](int h, int w) -> bool { return h >= 0 && h < n && w >= 0 && w < m; };
    auto getd = [&](int h, int w) -> int {
        char ch = grid[h][w];
        for (int i = 0; i < 4; ++i) {
            if ("RULD"[i] == ch) {
                return i;
            }
        }
        return -1;
    };

    // 加边
    vector<int> to(n * m), from(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int nh = i + dx[getd(i, j)];
            int nw = j + dy[getd(i, j)];
            if (check(nh, nw)) {
                to[get(i, j)] = get(nh, nw);
                from[get(nh, nw)] = get(i, j);
            } else {
                to[get(i, j)] = get(i, j);
                from[get(i, j)] = get(i, j);
            }
        }
    }

    vector<int> f(n * m, -1), dfn(n * m);

    int past = -1;
    int cir = 0;

    function<int(int, int)> dfs = [&](int u, int now) -> int {
        auto &r = f[u];
        if (r != -1) {
            return r;
        }
        if (dfn[u]) {
            cir = now - dfn[u];
            past = u;
            r = cir;
            return 0;
        }
        dfn[u] = now;
        int val = dfs(to[u], now + 1) + 1;

        // NOTE: 环上的每一个点的答案都是环的长度
        if (cir) {
            r = cir;
            if (u == past) {
                cir = 0;
            }
            return r;
        } else {
            return r = val;
        }
    };
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