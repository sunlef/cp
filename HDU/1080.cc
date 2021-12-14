#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int HAHA = 1e9;

map<pair<char, char>, int> mp;

void solve() {
    int n, m;
    string a, b;

    cin >> n >> a >> m >> b;

    a = '?' + a;
    b = '?' + b;

    if (n < m) {
        swap(n, m), swap(a, b);
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -INF));

    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i) {
        dp[0][i] = dp[0][i - 1] + mp[{'-', b[i]}];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + mp[{'-', a[i]}];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max({dp[i - 1][j] + mp[{a[i], '-'}], dp[i - 1][j - 1] + mp[{a[i], b[j]}]});
        }
    }

    cout << dp[n][m] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    mp[{'-', '-'}] = -HAHA;
    mp[{'A', 'A'}] = mp[{'T', 'T'}] = mp[{'C', 'C'}] = mp[{'G', 'G'}] = 5;
    mp[{'A', 'C'}] = mp[{'C', 'A'}] = -1;
    mp[{'A', 'G'}] = mp[{'G', 'A'}] = -2;
    mp[{'A', 'T'}] = mp[{'T', 'A'}] = -1;
    mp[{'A', '-'}] = mp[{'-', 'A'}] = -3;
    mp[{'C', 'G'}] = mp[{'G', 'C'}] = -3;
    mp[{'C', 'T'}] = mp[{'T', 'C'}] = -2;
    mp[{'C', '-'}] = mp[{'-', 'C'}] = -4;
    mp[{'G', 'T'}] = mp[{'T', 'G'}] = -2;
    mp[{'G', '-'}] = mp[{'-', 'G'}] = -2;
    mp[{'T', '-'}] = mp[{'-', 'T'}] = -1;

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}