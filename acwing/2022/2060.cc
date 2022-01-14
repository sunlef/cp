#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (string &i : grid) {
        cin >> i;
    }

    vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    auto valid = [&](int X, int Y) -> bool { return X >= 0 && X < N && Y >= 0 && Y < M; };

    function<void(int, int, int)> dfs = [&](int X, int Y, char color) {
        grid[X][Y] = color;
        for (auto &[dx, dy] : moves) {
            if (valid(X + dx, Y + dy) && grid[X + dx][Y + dy] == 'X') {
                dfs(X + dx, Y + dy, color);
            }
        }
    };

    char cnt = 'A';
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'X') {
                dfs(i, j, cnt++);
            }
        }
    }

    queue<tuple<int, int, int>> Q;
    deque<deque<bool>> visited(N, deque<bool>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'A') {
                Q.push({i, j, -1});
                visited[i][j] = true;
            }
        }
    }

    while (!Q.empty()) {
        auto [X, Y, step] = Q.front();
        Q.pop();

        if (grid[X][Y] == 'B') {
            cout << step << '\n';
            return 0;
        }

        for (auto &[dx, dy] : moves) {
            if (valid(X + dx, Y + dy) && !visited[X + dx][Y + dy]) {
                visited[X + dx][Y + dy] = true;
                Q.push({X + dx, Y + dy, step + 1});
            }
        }
    }

    return 0;
}