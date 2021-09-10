#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int SIZE = 110;
int dis[SIZE][SIZE];
int edge[SIZE][SIZE];
int pass[SIZE][SIZE];
bool visited[1003];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(dis, 0x3f, sizeof dis);
    memset(edge, -1, sizeof edge);
    memset(pass, -1, sizeof pass);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = edge[b][a] = i;
        dis[a][b] = dis[b][a] = c;
    }

    for (int i = 1; i <= N; ++i) {
        dis[i][i] = 0;
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (i != k && j != k && i != j && dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    pass[i][j] = k;
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) {
                continue;
            }
            vector<int> vec(1, i);
            function<void(int, int)> dfs = [&](int u, int v) {
                if (i == j) {
                    return;
                } else if (pass[u][v] == -1) {
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
                visited[edge[u][v]] = visited[edge[v][u]] = true;
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