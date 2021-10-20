#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> visited(n);

    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        visited[y - 1] = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    cout << i + 1 << ' ' << j + 1 << '\n';
                }
            }
            return;
        }
    }
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