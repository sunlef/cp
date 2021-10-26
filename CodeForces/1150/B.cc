#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (auto &row : grid) {
        cin >> row;
    }

    int di[] = {0, 1, 2, 1, 1};
    int dj[] = {0, 0, 0, -1, 1};

    auto check = [&](int h, int w) {
        for (int i = 0; i < 5; ++i) {
            if (h + di[i] < 0 || h + di[i] >= n) {
                return false;
            }
            if (w + dj[i] < 0 || w + dj[i] >= n) {
                return false;
            }
            if (grid[h + di[i]][w + dj[i]] != '.') {
                return false;
            }
        }
        return true;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.' && check(i, j)) {
                for (int k = 0; k < 5; ++k) {
                    grid[i + di[k]][j + dj[k]] = '!';
                }
            }
        }
    }

    for (auto &row : grid) {
        for(auto &ch : row) {
            if (ch == '.') {
                cout << "NO\n";
                return 0;
            }
        }
    } 
    cout << "YES\n";
    
    return 0;
}