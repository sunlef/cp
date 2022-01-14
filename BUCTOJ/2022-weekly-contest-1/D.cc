#include <bits/stdc++.h>
using namespace std;

int dis[100][100];
int edge[100][100];
int pass[100][100];
bool visited[1000];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    memset(dis, 0x3f, sizeof dis);
    memset(edge, -1, sizeof edge);
    memset(pass, -1, sizeof pass);
    memset(visited, 0, sizeof visited);

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
                    visited[edge[u][v]] = visited[edge[v][u]] = true;
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