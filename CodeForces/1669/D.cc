#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<string> a;

    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            if (pos == i) {
                pos = i + 1;
                continue;
            } else {
                a.push_back(s.substr(pos, i - pos));
                pos = i + 1;
            }
        }
    }

    if (pos != n) {
        a.push_back(s.substr(pos));
    }

    for (const string &i : a) {
        int cntr = 0, cntb = 0;
        for (char j : i) {
            if (j == 'R') {
                ++cntr;
            } else {
                ++cntb;
            }
        }

        if (cntr == 0 || cntb == 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int QvQ = 1; QvQ <= T; ++QvQ) {
        solve();
    }

    return 0;
}