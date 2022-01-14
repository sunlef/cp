#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int n = 1; n <= 1000; ++n) {
        vector<vector<char>> a(n + 1);
        int now = 1;
        string str = "happynewyear";

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < int(str.size()); ++j, ++now) {
                if (now == n + 1) {
                    now = 1;
                }
                a[now].push_back(str[j]);
            }
        }

        for (int i = 1; i <= n; ++i) {
            ranges::sort(a[i]);
        }

        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < int(a[i].size()); ++j) {
                if (j + 1 < int(a[i].size())) {
                    if (a[i][j] == a[i][j + 1]) {
                        ++cnt[i];
                        ++j;
                        continue;
                    }
                }
            }
        }

        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] > cnt[ans]) {
                ans = i;
            }
        }

        if (ans != 1) {
            cout << n << ' ' << ans << '\n';
        }
    }

    return 0;
}