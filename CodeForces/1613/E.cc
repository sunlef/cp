#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector grid(n, vector<char>(m));

    struct Node {
        int x, y;
    } L;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'L') {
                L = {i, j};
            }
        }
    }

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    queue<Node> q;
    q.push(L);

    auto hahaha = [&](int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '+' || grid[x][y] == '#' || grid[x][y] == 'L') {
            return false;
        }
        int res = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (grid[nx][ny] != '#') {
                ++res;
            }
        }
        if (res > 3) {
            return false;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (grid[nx][ny] == '+' || grid[nx][ny] == 'L') {
                return true;
            }
        }

        return false;
    };


    auto hahaha2 = [&](int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '+' || grid[x][y] == '#' || grid[x][y] == 'L') {
            return false;
        }
        int res = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (grid[nx][ny] == '.') {
                ++res;
            }
        }
        if (!(res > 1)) {
            return true;
        } else {
            return false;
        }
    };


    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        int x = now.x, y = now.y;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (hahaha2(nx, ny)) {
                q.push({nx, ny});
                grid[nx][ny] = '+';
            }
        }
    }

    for (auto &row : grid) {
        for (char &ch : row) {
            cout << ch;
        }
        cout << '\n';
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