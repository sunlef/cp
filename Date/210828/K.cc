#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    pair<int, bool> grid[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j].first;
            char ch;
            cin >> ch;
            if (ch == 'Y') {
                grid[i][j].second = true;
            } else {
                grid[i][j].second = false;
            }
        }
    }

    int w[m][n], v[m][n];
    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (j == n - 1) {
                if (grid[j][i].second) {
                    v[i][j] = 0;
                } else {
                    v[i][j] = 1;
                }
                w[i][j] = grid[j][i].first;
            } else {
                w[i][j] = w[i][j + 1];
                v[i][j] = v[i][j + 1];
                w[i][j] += grid[j][i].first;
                if (!grid[j][i].second) {
                    v[i][j]++;
                }
            }
        }
    }    

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            v[i][j]++;
        }
    }

    k += m;
    vector<int> dp(k + 1, 0);

    for (int i = 0; i < m; ++i) {
        for (int j = k; j >= 0; --j) {
            for (int k = 0; k < n; ++k) {
                if (v[i][k] <= j) {
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
                }
                cout << i << ' ' << k << ' ' << j << ' ' << dp[j] << '\n';
            }
        }
    }
    cout << dp[k] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}