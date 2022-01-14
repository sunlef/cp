#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    i64 n;
    cin >> n;

    i64 A = i64(pow(n + 0.5, 1.0 / 2));
    i64 B = i64(pow(n + 0.5, 1.0 / 3));
    i64 C = i64(pow(n + 0.5, 1.0 / 6));

    cout << A + B - C << '\n';
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