    #pragma GCC optimize(2)
    #include <bits/stdc++.h>
    using namespace std;
    using i64 = int64_t;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N, R;
        cin >> N >> R;

        vector<vector<i64>> grid(5001, vector<i64>(5001));
        for (int i = 0; i < N; ++i) {
            int x, y, v;
            cin >> x >> y >> v;
            grid[x][y] = v;
        }
        for (int i = 1; i < 5001; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < 5001; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < 5001; ++i) {
            for (int j = 1; j < 5001; ++j) {
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            }
        }

        auto sum = [&](int X0, int Y0, int X1, int Y1) -> i64 {
            return grid[X1][Y1] - (Y0 == 0 ? 0 : grid[X1][Y0 - 1]) - (X0 == 0 ? 0 : grid[X0 - 1][Y1]) +
                   (X0 == 0 || Y0 == 0 ? 0 : grid[X0 - 1][Y0 - 1]);
        };

        i64 ans = INT64_MIN;
        for (int i = R; i - 1 < 5001; ++i) {
            for (int j = R; j - 1 < 5001; ++j) {
                ans = max(ans, sum(i - R, j - R, i - 1, j - 1));
            }
        }

        cout << ans << '\n';

        return 0;
    }