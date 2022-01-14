#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<pair<int, int>> R(N);
    set<pair<int, int>> sR;

    for (auto &pr : R) {
        auto &[l, r] = pr;
        cin >> l >> r;
        sR.insert(pr);
    }

    for (auto [l, r] : R) {
        if (l == r) {
            cout << l << ' ' << l << ' ' << l << '\n';
        } else {
            bool ok = false;
            for (int i = l + 1; i <= r - 1; ++i) {
                if (sR.count({l, i - 1}) && sR.count({i + 1, r})) {
                    ok = true;
                    cout << l << ' ' << r << ' ' << i << '\n';
                    break;
                }
            }
            if (!ok) {
                if (sR.count({l + 1, r})) {
                    cout << l << ' ' << r << ' ' << l << '\n';
                    continue;
                } else if (sR.count({l, r - 1})) {
                    cout << l << ' ' << r << ' ' << r << '\n';
                    continue;
                } else {
                    assert(false);
                }
            }
        }
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