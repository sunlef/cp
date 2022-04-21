#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (string &i : grid) {
        cin >> i;
    }

    cout << '\n';

    auto calc = [&]() {
        auto res = grid;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if (res[i][j] == '*' && res[i + 1][j] == '.') {
                    res[i][j] = '.';
                    res[i + 1][j] = '*';
                }
            }
        }
        return res;
    };

    auto v = calc();
    while (v != grid) {
        v = grid;
        grid = calc();
    }

    for (const string &i : grid) {
        cout << i << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int QvQ = 1; QvQ <= T; ++QvQ) {
        solve();
    }

    return 0;
}