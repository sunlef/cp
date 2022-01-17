#include <bits/stdc++.h>
using namespace std;

void solve() {
    int L;
    int x, y, r, c;
    cin >> L >> x >> y >> r >> c;

    vector<pair<int, int>> moves = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
    auto check = [&](int X, int Y) { return X >= 0 && X < L && Y >= 0 && Y < L; };

    deque<deque<bool>> visited(L, deque<bool>(L));
    visited[x][y] = true;

    queue<tuple<int, int, int>> Q;
    Q.push({x, y, 0});

    while (!Q.empty()) {
        auto [X, Y, step] = Q.front();
        Q.pop();

        if (X == r && Y == c) {
            cout << step << '\n';
            return;
        }

        for (auto [dx, dy] : moves) {
            int nx = X + dx, ny = Y + dy;
            if (check(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                Q.push({nx, ny, step + 1});
            }
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