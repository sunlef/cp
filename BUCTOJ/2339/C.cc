#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    bool first = true;

    while (cin >> n) {
        if (!first) {
            std::cout << "\n";
        }

        std::vector<vector<int>> grid(n, std::vector<int>(n, 1));

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] = 0;
                if (i - 1 >= 0) {
                    grid[i][j] += grid[i - 1][j - 1];
                    if (j < i) {
                        grid[i][j] += grid[i - 1][j];
                    }
                }
            }
        }

        auto calc = [](int x) -> int {
            int res = 0;
            while (x) {
                ++res;
                x /= 10;
            }
            return res;
        };

        int len = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                len = max(len, calc(grid[i][j]));
            }
        }

        for (int i = 0; i < n; ++i) {
            bool first_ = true;
            for (int j = 0; j <= i; ++j) {
                if (!first_) {
                    int tlen = calc(grid[i][j]);
                    int d = len - tlen;
                    for (int i = 0; i <= d; ++i) {
                        std::cout << ' ';
                    }
                }
                std::cout << grid[i][j];
                first_ = false;
            }
            std::cout << "\n";
        }

        first = false;
    }

    return 0;
}