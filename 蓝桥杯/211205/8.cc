#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> e(n);

    for (int u = 0, v; u < n; ++u) {
        cin >> v;
        --v;
        e[u] = v;
    }

    vector<int> visited(n);

    function<void(int u)> dfs = [&](int u) -> void {
        // visited[u] = 1;
        // if (!visited[e[u]]) {
        //     dfs(e[u]);
        // }
        while (!visited[u]) {
            visited[u] = 1;
            u = e[u];
        }
    };

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++res;
            dfs(i);
        }
    }

    cout << res << '\n';
    return 0;
}