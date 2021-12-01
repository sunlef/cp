#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    if (a > b) {
        swap(a, b);
    }

    int cnt = (a + b) / 4;
    if (a >= cnt) {
        cout << cnt << '\n';
    } else {
        cout << a << '\n';
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