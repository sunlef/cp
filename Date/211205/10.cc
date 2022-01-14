#include <bits/stdc++.h>
#define W first
#define U second
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (auto &row : grid) {
        for (auto &x : row) {
            cin >> x;
        }
    }

    auto get_index = [&](int i, int j) -> int { return i * m + j; };
    auto check = [&](int i, int j) -> bool { return i >= 0 && i < n && j >= 0 && j < m; };

    vector<vector<pair<int, int>>> edge(n * m);
    vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (auto &pr : moves) {
                int di = pr.first, dj = pr.second;
                if (grid[i][j] == '1' && check(i + di, j + dj)) {
                    edge[get_index(i + di, j + dj)].push_back({0, get_index(i, j)});
                } else if (grid[i][j] == '2' && check(i + di, j + dj) && grid[i + di][j + dj] != '2') {
                    edge[get_index(i + di, j + dj)].push_back({1, get_index(i, j)});
                }
            }
        }
    }

    constexpr int INF = 1e9 + 114514;
    vector<int> dist(n * m, INF);
    vector<int> visited(n * m);
    dist[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int DIS = q.top().W, u = q.top().U;
        q.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = 1;

        for (auto x : edge[u]) {
            int w = x.W, v = x.U;
            if (dist[v] > DIS + w) {
                dist[v] = DIS + w;
                q.push({dist[v], v});
            }
        }
    }

    if (dist[get_index(n - 1, m - 1)] > 1e9) {
        cout << "-1\n";
    } else {
        cout << dist[get_index(n - 1, m - 1)] << '\n';
    }

    return 0;
}