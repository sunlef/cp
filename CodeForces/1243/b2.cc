#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(26);
    string s, t;
    cin >> s >> t;
    for (auto &ch : s) {
        ++cnt[ch - 'a'];
    }
    for (auto &ch : t) {
        ++cnt[ch - 'a'];
    }
    for (auto &x : cnt) {
        if (x % 2 != 0) {
            cout << "no\n";
            return;
        }
    }

    using pii = pair<int, int>;
    vector<pii> ans;

    auto work = [&](int pos) {
        char ch = s[pos];
        int flag = -1;
        for (int i = pos + 1; i < n; ++i) {
            if (s[i] == ch) {
                flag = i;
                break;
            }
        }
        if (flag != -1) {
            ans.push_back({flag + 1, pos + 1});
            swap(s[flag], t[pos]);
        } else {
            for (int i = pos + 1; i < n; ++i) {
                if (t[i] == ch) {
                    flag = i;
                    break;
                }
            }
            ans.push_back({n, flag + 1});
            swap(s[n - 1], t[flag]);
            ans.push_back({n, pos + 1});
            swap(s[n - 1], t[pos]);
        }
    };

    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            work(i);
        }
    }

    cout << "yes\n";
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) {
        cout << x << ' ' << y << '\n';
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