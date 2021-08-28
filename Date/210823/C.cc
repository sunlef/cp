#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    using TII = tuple<int, int>;
    using TIII = tuple<int, int, int>;
    priority_queue<TIII, vector<TIII>, greater<TIII>> q;
    queue<TII> vec;

    vector<vector<char>> grid(R + 2, vector<char>(C + 2, '#'));
    vector<vector<int>> cost(R + 2, vector<int>(C + 2, -INT_MAX));
    vector<vector<int>> dist(R + 2, vector<int>(C + 2, INT_MAX));
    vector<vector<vector<TII>>> port(4, vector<vector<TII>>(R + 2, vector<TII>(C + 2, make_tuple(-INT_MAX, -INT_MAX))));

    for (int i = 0; i < R + 2; ++i) {
        for (int j = 0; j < C + 2; ++j) {
            if (i && j && i != R + 1 && j != C + 1) {
                cin >> grid[i][j];
            }
            if (grid[i][j] == '#') {
                vec.push(make_tuple(i, j));
                cost[i][j] = 0;
            } else if (grid[i][j] == 'S') {
                dist[i][j] = 0;
                q.push(make_tuple(0, i, j));
            }
        }
    }

    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};

    auto check = [&](int r, int c) -> bool {
        return r >= 0 && r < R + 2 && c >= 0 && c < C + 2 && grid[r][c] != '#' && cost[r][c] == -INT_MAX;
    };

    while ((bool)vec.size()) {
        int r = get<0>(vec.front()), c = get<1>(vec.front());
        vec.pop();
        for (int d = 0; d < 4; ++d) {
            int nr = r + dx[d], nc = c + dy[d];
            if (check(nr, nc)) {
                cost[nr][nc] = cost[r][c] + 1;
                vec.push(make_tuple(nr, nc));
            }
        }
    }

    auto ops = [](int d) -> int { return (d + 2) % 4; };

    function<TII(int, int, int)> dfs = [&](int r, int c, int d) -> TII {
        if (port[d][r][c] == make_tuple(-INT_MAX, -INT_MAX)) {
            if (grid[r][c] == '#') {
                return port[d][r][c] = make_tuple(r + dx[ops(d)], c + dy[ops(d)]);
            } else {
                return port[d][r][c] = dfs(r + dx[d], c + dy[d], d);
            }
        } else {
            return port[d][r][c];
        }
    };


    while ((bool)q.size()) {
        while (get<0>(q.top()) > dist[get<1>(q.top())][get<2>(q.top())]) q.pop();
        if (q.empty()) break;

        int DIST = get<0>(q.top()), r = get<1>(q.top()), c = get<2>(q.top());
        q.pop();

        if (grid[r][c] == 'C') {
            cout << DIST << '\n';
            return 0;
        }

        for (int d = 0; d < 4; ++d) {
            int nr = r + dx[d], nc = c + dy[d];
            if (grid[nr][nc] != '#' && dist[nr][nc] > DIST + 1) {
                dist[nr][nc] = DIST + 1;
                q.push(make_tuple(dist[nr][nc], nr, nc));
            }
            TII v = dfs(r, c, d);
            if (grid[get<0>(v)][get<1>(v)] != '#' && dist[get<0>(v)][get<1>(v)] > DIST + cost[r][c]) {
                dist[get<0>(v)][get<1>(v)] = DIST + cost[r][c];
                q.push(make_tuple(dist[get<0>(v)][get<1>(v)], get<0>(v), get<1>(v)));
            }
        }
    }

    return 0;
}

