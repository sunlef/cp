#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    auto all = [&](int x, char ch) -> bool {
        if (a[x] == ch && b[x] == ch) {
            return true;
        } else {
            return false;
        }
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) {
            ans += 2;
        } else if (a[i] == '1' && b[i] == '1') {
            if (i == n - 1) {
                break;
            } else if (all(i + 1, '0')) {
                ans += 2;
                ++i;
            }
        } else {
            if (i == n - 1) {
                ans += 1;
            } else if (all(i + 1, '1')) {
                ans += 2;
                ++i;
            } else {
                ans += 1;
            }
        }
    }

    cout << ans << '\n';
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