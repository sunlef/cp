#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> grid(N);
    for (string &i : grid) {
        cin >> i;
    }
    if (grid.front().front() == ')') {
        cout << "0\n";
        return 0;
    }

    deque<deque<bool>> visited(N, deque<bool>(N));
    visited[0][0] = true;

    int ans = 0;
    function<void(int, int, int, int, bool)> dfs = [&](int x, int y, int len_left, int len_right, bool goback) {
        if (goback && len_left == len_right) {
            ans = max(ans, 2 * len_left);
            return;
        }

        for (auto &[dx, dy] : vector<pair<int, int>>({{-1, 0}, {1, 0}, {0, -1}, {0, 1}})) {
            int nx = x + dx, ny = y + dy;
            auto check = [&](int X, int Y) -> bool { return X >= 0 && X < N && Y >= 0 && Y < N && !visited[X][Y]; };

            if (check(nx, ny)) {
                if (grid[nx][ny] == '(') {
                    if (!goback) {
                        visited[nx][ny] = true;
                        dfs(nx, ny, len_left + 1, 0, false);
                        visited[nx][ny] = false;
                    }
                } else {
                    visited[nx][ny] = true;
                    dfs(nx, ny, len_left, len_right + 1, true);
                    visited[nx][ny] = false;
                }
            }
        }
    };

    dfs(0, 0, 1, 0, false);

    cout << ans << '\n';
    return 0;
}