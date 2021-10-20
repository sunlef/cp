#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int HI = a + b + c - 3;
    int LOW = max(0, max({a, b, c}) - (a + b + c - max({a, b, c})) - 1);
    
    if (LOW <= m && m <= HI) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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