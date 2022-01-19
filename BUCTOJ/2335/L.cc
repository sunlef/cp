#include <bits/stdc++.h>
using namespace std;

void solve() {
    int M;
    cin >> M;

    map<string, map<string, int>> mp;
    for (int i = 0; i < M; ++i) {
        string a, b;
        int c;
        cin >> a >> b >> c;
        mp[b][a] += c;
    }

    for (auto &[a, b] : mp) {
        cout << a << '\n';
        for (auto &[c, d] : b) {
            cout << "  |----" << c << '(' << d << ")\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
        if (TwT < T) {
            cout << '\n';
        }
    }

    return 0;
}