#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    auto check_0 = [&]() -> bool {
        int l = 0, r = n - 1;
        while (l < r) {
            if (a[l] != a[r]) {
                return false;
            }
            ++l, --r;
        }
        return true;
    };

    auto check_l = [&]() -> bool {
        int l = 0, r = n - 1;
        while (l < r && a[l] == a[r]) {
            ++l, --r;
        }
        int x = a[l];
        while (l < r) {
            if (a[l] != a[r]) {
                if (a[l] == x) {
                    ++l;
                    continue;
                } else if (a[r] == x) {
                    --r;
                    continue;
                } else {
                    return false;
                }
            }
            ++l, --r;
        }
        return true;
    };

    auto check_r = [&]() -> bool {
        int l = 0, r = n - 1;
        while (l < r && a[l] == a[r]) {
            ++l, --r;
        }
        int x = a[r];
        while (l < r) {
            if (a[l] != a[r]) {
                if (a[l] == x) {
                    ++l;
                    continue;
                } else if (a[r] == x) {
                    --r;
                    continue;
                } else {
                    return false;
                }
            }
            ++l, --r;
        }
        return true;
    };

    if (check_0() || check_l() || check_r()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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