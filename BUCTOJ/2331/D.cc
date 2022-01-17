#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;

    auto check = [](const string& str) -> bool { return string(str.begin(), str.end()) == string(str.rbegin(), str.rend()); };
    bool ok = false;

    for (int i = 0; i < int(S.size()); ++i) {
        string now = S;
        for (char ch = 'a'; ch < 'z'; ++ch) {
            if (ch == S[i]) {
                continue;
            }
            now[i] = ch;
            if (check(now)) {
                ok = true;
            }
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
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