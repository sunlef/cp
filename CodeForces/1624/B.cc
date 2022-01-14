#include <bits/stdc++.h>
using namespace std;

void solve() {
    int A, B, C;
    cin >> A >> B >> C;

    auto check1 = [&]() -> bool {
        int d = B - A;
        return (B + d) % C == 0 && (B + d) > 0;
    };

    auto check2 = [&]() -> bool {
        int d = C - B;
        return (B - d) % A == 0 && (B - d) > 0;
    };

    auto check3 = [&]() -> bool {
        int d = C - A;
        if (d % 2 != 0) {
            return false;
        }
        d /= 2;
        return (A + d) % B == 0 && (A + d) > 0;
    };

    bool ok = false;
    ok |= check1();
    ok |= check2();
    ok |= check3();

    cout << (ok ? "YES\n" : "NO\n");
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
