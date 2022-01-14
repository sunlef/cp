#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R, C;
    cin >> N >> R >> C;

    vector<vector<int>> occupied(1010, vector<int>(1010));
    while (N--) {
        int x, y;
        cin >> x >> y;
        ++occupied[x][y];
    }

    vector<vector<int>> distance(1010, vector<int>(1010, INT_MAX));
    distance[R][C] = 0;

    vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    using Node = tuple<int, int, int>;
    auto valid = [&](int X, int Y) -> bool { return X >= 0 && X < 1010 && Y >= 0 && Y < 1010; };

    deque<Node> Q;
    Q.push_front({0, R, C});
    while (!Q.empty()) {
        auto [dist, x, y] = Q.front();
        Q.pop_front();

        if (x == 0 && y == 0) {
            cout << dist << '\n';
            return 0;
        }

        for (auto &[dx, dy] : moves) {
            int nx = x + dx;
            int ny = y + dy;
            if (valid(nx, ny) && distance[nx][ny] > dist + occupied[nx][ny]) {
                int nd = dist + occupied[nx][ny];
                distance[nx][ny] = nd;
                if (nd >= get<0>(Q.back())) {
                    Q.push_back({nd, nx, ny});
                } else {
                    Q.push_front({nd, nx, ny});
                }
            }
        }
    }

    return 0;
}