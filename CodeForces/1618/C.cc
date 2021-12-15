#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    int n;
    cin >> n;

    vector<i64> a(n);
    for (i64 &ai : a) {
        cin >> ai;
    }

    auto check1 = [&](i64 x) -> bool {
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0 && a[i] % x == 0) {
                return false;
            }
            if (i % 2 == 1 && a[i] % x != 0) {
                return false;
            }
        }
        return true;
    };

    auto check2 = [&](i64 x) -> bool {
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0 && a[i] % x != 0) {
                return false;
            }
            if (i % 2 == 1 && a[i] % x == 0) {
                return false;
            }
        }
        return true;
    };

    i64 even = 0, odd = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            even = std::gcd(even, a[i]);
        } else {
            odd = std::gcd(odd, a[i]);
        }
    }

    if (check1(even) || check2(even)) {
        cout << even << '\n';
    } else if (check1(odd) || check2(odd)) {
        cout << odd << '\n';
    } else {
        cout << "0\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}