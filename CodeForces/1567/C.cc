#include <bits/stdc++.h>
using namespace std;

void solve() {
    string n;
    cin >> n;
    int a = 0, b = 0;

    for (int i = 0; i < int(n.size()); ++i) {
        if (i % 2 == 0) {
            a = 10 * a + n[i] - '0';
        } else {
            b = 10 * b + n[i] - '0';
        }
    }

    cout << (a + 1) * (b + 1) - 2 << '\n';
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