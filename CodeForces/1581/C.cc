#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));

    for (auto &row : a) {
        for (auto &ch : row) {
            cin >> ch;
        }
    }
    vector<vector<int64_t>> pre(n + 1, vector<int64_t>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1];
            pre[i][j] -= pre[i - 1][j - 1];
            pre[i][j] += a[i - 1][j - 1];
        }
    }

    auto sum = [&](int X1, int Y1, int X2, int Y2) { return pre[X2][Y2] - pre[X2][Y1 - 1] - pre[X1 - 1][Y2] + pre[X1 - 1][Y1 - 1]; };

    int ans = 16;
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