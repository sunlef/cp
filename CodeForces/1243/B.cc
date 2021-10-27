#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            pos.push_back(i);
        }
    }

    if (pos.size() == 0) {
        cout << "yes\n";
    } else if (pos.size() == 1) {
        cout << "no\n";
    } else if (pos.size() == 2) {
        int p0 = pos[0], p1 = pos[1];
        if (s[p0] == s[p1] && t[p0] == t[p1] ) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    } else {
        cout << "no\n";
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