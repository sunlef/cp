#include <bits/stdc++.h>
using namespace std;

void solve() {
    string n;
    cin >> n;
    int ans = n.size() + 1;

    using i64 = long long;
    for (i64 t = 1; t < (1ll << 59); t <<= 1) {
        string tt = to_string(t);
        int cnt = n.size();
        for (int i = 0, j = 0; i < (int)n.size() && j < (int)tt.size(); ++i) {
            if (n[i] == tt[j]) {
                --cnt;
                ++j;
                ans = min(ans, cnt + (int)tt.size() - j);
            }
        }
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


