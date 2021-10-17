#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, H;
    cin >> n >> H;
    vector<int> weapon(n);
    for (auto &x : weapon) {
        cin >> x;
    }
    sort(weapon.rbegin(), weapon.rend());

    if (weapon[0] >= H) {
        cout << 1 << '\n';
    } else {
        auto total = weapon[0] + weapon[1];
        auto T = H / total;
        if (__int128_t(T * total) >= H) {
            cout << 2 * T << '\n';
        } else {
            if (__int128_t(T * total + weapon[0]) >= H) {
                cout << 2 * T + 1 << '\n';
            } else {
                cout << 2 * T + 2 << '\n';
            }
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