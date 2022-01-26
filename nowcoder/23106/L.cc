#include <bits/stdc++.h>
using namespace std;

void solve() {
    auto calc = [](int x, int y) -> double { return sqrt(double(x * x) + y * y); };
    int n;
    cin >> n;

    string s;
    cin >> s;

    double ans = 0;

    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            --x;
        } else if (s[i] == 'R') {
            ++x;
        } else if (s[i] == 'U') {
            ++y;
        } else {
            --y;
        }

        ans = max(ans, calc(x, y));
    }

    cout << fixed << setprecision(10) << ans << '\n';
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