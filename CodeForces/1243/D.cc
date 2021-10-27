#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> cnt(n, n - 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        --cnt[u], --cnt[v];
    }
    cout << "!!!\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ' ' << cnt[i] << '\n';
    }

    return 0;
}