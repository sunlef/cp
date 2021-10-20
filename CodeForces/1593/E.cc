#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> G(n);
    vector<int> visited(n), deg(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> bfs;

    for (int i = 0; i < n; ++i) {
        deg[i] = G[i].size();
        if (deg[i] <= 1) {
            bfs.push_back(i);
            visited[i] = 1;
        }
    }

    for (int i = 0; i < k - 1; ++i) {
        if (bfs.size() == 0) {
            break;
        }

        vector<int> nbfs;
        for (auto &u : bfs) {
            for (auto &v : G[u]) {
                --deg[v];
                if (deg[v] == 1) {
                    nbfs.push_back(v);
                    visited[v] = 1;
                }
            }
        }

        bfs = nbfs;
    }

    cout << count(visited.begin(), visited.end(), 0) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}