#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(2, vector<char> (n));
    for (auto &row :grid) {
        for (auto &ch : row) {
            cin >> ch;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (grid[0][i] == grid[1][i] && grid[0][i] == '1') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}