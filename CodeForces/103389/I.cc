#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

    int nowh = -1, noww = -1, v = 0, d = 2;

    vector grid(n, vector<char>(m));

    auto check = [&](int h, int w) -> bool { return h >= 0 && h < n && w >= 0 && w < m && grid[h][w] != '#'; };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            auto &ch = grid[i][j];
            cin >> ch;
            if (ch == '*') {
                nowh = i, noww = j;
            }
        }
    }

    int q;
    cin >> q;

    string s;
    cin >> s;

    for (auto &ch : s) {
        if (ch == 'U') {
            ++v;
        } else if (ch == 'D') {
            v = max(0, v - 1);
        } else if (ch == 'L') {
            d = (d + 1) % 8;
        } else {
            d = ((d - 1) % 8 + 8) % 8;
        }

        bool ok = true;
        for (int i = 0; i < v; ++i) {
            int nh = nowh + dx[d];
            int nw = noww + dy[d];

            if (!check(nh, nw)) {
                ok = false;
                v = 0;
                break;
            } else if (d % 2 != 0) {
                if (grid[nh][noww] == '#' && grid[nowh][nw] == '#') {
                    ok = false;
                    v = 0;
                    break;
                }
            }
            nowh = nh, noww = nw;
        }

        if (!ok) {
            cout << "Crash! ";
        }
        cout << nowh + 1 << ' ' << noww + 1 << '\n';
    }

    return 0;
}