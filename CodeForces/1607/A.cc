#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(26);
    for (int i = 0; i < 26; ++i) {
        char ch;
        cin >> ch;
        a[ch - 'a'] = i;
    }
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 1; i < int(str.size()); ++i) {
        ans += abs(a[str[i] - 'a'] - a[str[i - 1] - 'a']);
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