#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (auto &row : grid) {
        for (int &i : row) {
            cin >> i;
        }
    }

    auto check = [&](int X, int Y) -> bool { return X >= 0 && X < n && Y >= 0 && Y < m; };

    vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<pair<int, int>> ans;
    vector<vector<int>> visited(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j] == 0) {

                [&](int X, int Y) -> void {
                    queue<tuple<int, int, bool>> Q;
                    vector<pair<int, int>> A, B;
                    Q.push({X, Y, true});
                    visited[X][Y] = 1;

                    while (!Q.empty()) {
                        auto [x, y, c] = Q.front();
                        Q.pop();

                        if (c) {
                            A.push_back({x, y});
                        } else {
                            B.push_back({x, y});
                        }

                        for (auto &[dx, dy] : moves) {
                            int nx = x + dx, ny = y + dy;
                            if (check(nx, ny) && !visited[nx][ny] && grid[nx][ny] == grid[X][Y]) {
                                Q.push({nx, ny, !c});
                                visited[nx][ny] = 1;
                            }
                        }
                    }

                    if (A.size() < B.size()) {
                        for (auto &[x, y] : A) {
                            ans.push_back({x, y});
                        }
                    } else {
                        for (auto &[x, y] : B) {
                            ans.push_back({x, y});
                        }
                    }
                }(i, j);
            }
        }
    }

    if (ans.size() == 0) {
        cout << "0 0\n";
    } else {
        cout << "1 " << ans.size() << '\n';
        for (auto &[x, y] : ans) {
            cout << x + 1 << ' ' << y + 1 << " 1 \n";
        }
    }

    return 0;
}