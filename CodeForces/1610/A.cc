#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << "0\n";
    } else if (n == 1 || m == 1) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
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