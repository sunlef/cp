#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    s.back() = s.front();
    cout << s << '\n';
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