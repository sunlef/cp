#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = a;
    int res;
    int A = a - 1;
    
    if (A % 4 == 0) {
        res = A;
    } else if (A % 4 == 1) {
        res = 1;
    } else if (A % 4 == 2) {
        res = A + 1;
    } else {
        res = 0;
    }


    if (res == b) {
        cout << ans << '\n';
    } else {
        if ((res ^ b) == a) {
            cout << ans + 2 << '\n';
        } else {
            cout << ans + 1 << '\n';
        }
    }
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