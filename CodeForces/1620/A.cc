#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if (ranges::count(s, 'N') == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}