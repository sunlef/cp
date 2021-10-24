#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = INT_MAX;

    auto calc = [&] (char ch) {
        int l = 0, r = n - 1;
        int res = 0;
        while (l < r) {
            if (s[l] == s[r]) {
                ++l, --r;
            } else {
                if (s[l] == ch) {
                    ++res;
                    ++l;
                } else if (s[r] == ch) {
                    ++res;
                    --r;
                } else {
                    return INT_MAX;
                }
            }
        }
        return res;
    };

    for (auto ch = 'a'; ch <= 'z'; ++ch) {
        ans = min(ans, calc(ch));
    }

    if (ans == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
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