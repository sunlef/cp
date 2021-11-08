#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<char, vector<string>> mp;

    mp['Y'].emplace_back("QQQ");
    mp['V'].emplace_back("QQW");
    mp['G'].emplace_back("QQE");
    mp['C'].emplace_back("WWW");
    mp['X'].emplace_back("QWW");
    mp['Z'].emplace_back("WWE");
    mp['T'].emplace_back("EEE");
    mp['F'].emplace_back("QEE");
    mp['D'].emplace_back("WEE");
    mp['B'].emplace_back("QWE");

    for (auto &[x, v] : mp) {
        auto now = v.front();
        for (int i = 1; i < 6; ++i) {
            ranges::next_permutation(now);
            v.emplace_back(now);
        }
    }

    string s;
    cin >> s;

    vector dp(s.size(), vector<int>(6, INT_MAX));
    ranges::fill(dp[0], 3);

    constexpr auto calc = [](const string &from, const string &to) {
        if (from[0] == to[0] && from[1] == to[1] && from[2] == to[2]) {
            return 0;
        } else if (from[1] == to[0] && from[2] == to[1]) {
            return 1;
        } else if (from[2] == to[0]) {
            return 2;
        } else {
            return 3;
        }
    };

    for (int i = 1; i < int(s.size()); ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 6; ++k) {
                char last = s[i - 1], now = s[i];
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + calc(mp[last][k], mp[now][j]));
            }
        }
    }

    int ans = INT_MAX;
    for (auto &res : dp.back()) {
        ans = min(ans, res);
    }

    cout << ans + s.size() << '\n';
    return 0;
}