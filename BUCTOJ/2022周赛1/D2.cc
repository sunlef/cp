#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dis(100, vector<int>(100, INT_MAX));
vector<vector<int>> edge(100, vector<int>(100, -1));
vector<vector<int>> pass(100, vector<int>(100, -1));
vector<int> visited(1000, 0);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edge[a][b] = edge[b][a] = i;
        dis[a][b] = dis[b][a] = c;
    }

    for (int i = 0; i < N; ++i) {
        dis[i][i] = 0;
    }

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


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                vector<int> vec(1, i);
                function<void(int, int)> dfs = [&](int u, int v) -> void {
                    if (pass[u][v] == -1) {
                        vec.emplace_back(v);
                    } else {
                        int k = pass[u][v];
                        dfs(u, k);
                        dfs(k, v);
                    }
                };
                dfs(i, j);
                for (int i = 1; i < int(vec.size()); ++i) {
                    int u = vec[i - 1], v = vec[i];
                    visited[edge[u][v]] = visited[edge[v][u]] = 1;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        if (!visited[i]) {
            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}