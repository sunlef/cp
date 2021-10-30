#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector grid(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }

    int x = grid[1][1];
    if (x % 7 == 0) {
        if (m != 1) {
            cout << "No\n";
            return 0;
        } else {
            for (int i = 2; i <= n; ++i) {
                if (grid[i][1] != grid[i - 1][1] + 7) {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }

    int R = x / 7 + 1;
    int C = x - 7 * (R - 1);

    for (int j = 1; j < m; ++j) {
        if (grid[1][j] % 7 == 0) {
            cout << "No\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] != 7 * (R + i - 2) + C + j - 1) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    return 0;
}