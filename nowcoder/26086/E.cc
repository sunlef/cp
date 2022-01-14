#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    int n;
    cin >> n;

    vector<i64> q(n), u(n);
    for (i64 &i : q) {
        cin >> i;
    }
    for (i64 &i : u) {
        cin >> i;
    }

    auto calc = [&](int CUT) -> i64 {
        map<i64, i64> mp;
        for (int i = 0; i < CUT; ++i) {

        }
    };
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