#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<pair<int, int>> edges(N - 1);
    vector<vector<int>> adj(N);

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        edges[i] = {u, v};
    }

    for (auto i : adj) {
        if (i.size() > 2) {
            cout << "-1\n";
            return;
        }
    }

    
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