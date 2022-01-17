#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    ranges::for_each(s, [&](char ch) { ++cnt[ch - 'a']; });

    string ans;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] == 2) {
            ans.push_back(i + 'a');
            ans.push_back(i + 'a');
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] == 1) {
            ans.push_back(i + 'a');
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}