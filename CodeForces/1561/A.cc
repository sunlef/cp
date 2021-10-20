#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    int idx = 1;
    auto check = [&]() -> bool {
        for (int i = 1; i <= n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                return false;
            }
        }
        return true;
    };

    auto work = [&](int x) -> void {
        if (x & 1) {
            for (int i = 1; i <= n - 2; i += 2) {
                if (a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                }
            }
        } else {
            for (int i = 2; i <= n - 1; i += 2) {
                if (a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                }
            }
        }
    };

    while (!check()) {
        work(idx);
        ++ans, ++idx;
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