#include <bits/stdc++.h>
using namespace std;
x
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    vector<vector<double>> dp(N + 1, vector<double>(2));

    dp[0][0] = 1;
    dp[0][1] = 0;

    vector<vector<int>> path(N + 1, vector<int>(2));
    path[0][0] = 0;
    path[0][1] = 1;

    for (int i = 1; i <= N; ++i) {
        int X = a[i];
        if (dp[i - 1][0] > dp[i - 1][1] / X) {
            path[i][0] = 0;
            dp[i][0] = dp[i - 1][0];
        } else {
            path[i][0] = 1;
            dp[i][0] = dp[i - 1][1] / X;
        }

        if (dp[i - 1][1] > dp[i - 1][0] * X) {
            dp[i][1] = dp[i - 1][1];
            path[i][1] = 0;
        } else {
            dp[i][1] = dp[i - 1][0] * X;
            path[i][1] = 1;
        }
    }

    function<void(int, int)> dfs = [&](int X, int T) -> void {
        if (X == 0) {
            return;
        }
        if (path[X][T] == 0) {
            dfs(X - 1, T);
        } else {
            dfs(X - 1, !T);
        }
        cout << path[X][T] << ' ';
    };

    dfs(N, 0);
    cout << endl;

    return 0;
}