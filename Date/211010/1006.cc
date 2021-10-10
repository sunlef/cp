#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t x;
    cin >> x;
    if (x == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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