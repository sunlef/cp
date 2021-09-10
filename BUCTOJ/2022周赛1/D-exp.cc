#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    using pii = pair<int, int>;
    using i64 = int64_t;
    vector<vector<i64>> dis(N, vector<i64>(N, LLONG_MAX));
    vector<vector<pii>> edge(N, vector<pii>(N, {INT_MAX, INT_MAX}));

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edge[a][b] = edge[b][a] = {c, i};
        dis[a][b] = dis[b][a] = c;
    }

    for (int i = 0; i < N; ++i) {
        dis[i][i] = 0;
    }

    vector<vector<int>> pass(N, vector<int>(N, -INT_MAX));

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    pass[i][j] = k;
                }
            }
        }
    }

    vector<int> visted(M, 0);

    function<void(int, int)> dfs = [&](int u, int v) -> void {
        if (u == v || pass[u][v] == -INT_MAX) {
            return;
        }
        visted[edge[u][pass[u][v]].second] = 1;
        visted[edge[v][pass[u][v]].second] = 1;
        dfs(u, pass[u][v]);
        dfs(pass[u][v], v);
    };

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dfs(i, j);
        }
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        if (!visted[i]) {
            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}