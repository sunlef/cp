#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    char NOW_MIN = CHAR_MAX, NOW_MAX = CHAR_MIN;

    int64_t ans = 1;

    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            if (s[i] == NOW_MIN && s[i] == NOW_MAX) {
                ans = ans * 2 % MOD;
            }
        }
        NOW_MIN = min(s[i], NOW_MIN);
        NOW_MAX = max(s[i], NOW_MAX);
    }

    cout << ans << '\n';
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