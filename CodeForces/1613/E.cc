#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n, string(m, '?'));

    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'L') 
                q.push({i, j});
        }
    }

    vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    auto out = [&](int x, int y) -> bool { return x < 0 || x >= n || y < 0 || y >= m; };

    auto check = [&](int x, int y) -> bool {
        if (out(x, y) || grid[x][y] == 'L' || grid[x][y] == '#' || grid[x][y] == '+') 
            return false;
        int liberty = 0;
        for (auto [dx, dy] : moves) {
            int nx = x + dx, ny = y + dy;
            if (!out(nx, ny) && grid[nx][ny] == '.') 
                ++liberty;
        }
        return liberty <= 1;
    };

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : moves) {
            int nx = x + dx, ny = y + dy;
            if (check(nx, ny)) {
                grid[nx][ny] = '+';
                q.push({nx, ny});
            }
        }
    }

    for (auto row : grid) cout << row << '\n';
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