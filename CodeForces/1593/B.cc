#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int ans = INT_MAX;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[i] == '2' && s[j] == '5') {
                ans = min(ans, int(s.size() - j + j - i - 2));
            }
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[i] == '7' && s[j] == '5') {
                ans = min(ans, int(s.size() - j + j - i - 2));
            }
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[i] == '5' && s[j] == '0') {
                ans = min(ans, int(s.size() - j + j - i - 2));
            }
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j)
            for (int k = j + 1; k < s.size(); ++k) {
                if (s[j] == '0' && s[k] == '0') {
                    ans = min(ans, int(s.size() - k - 1 + k - j - 1 + j - i - 1));
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