#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    int64_t total = 0;
    vector<int64_t> strength(n);
    for (auto &x : strength) {
        cin >> x;
        total += x;
    }
    sort(strength.begin(), strength.end(), greater<int64_t>());

    int m;
    cin >> m;
    while (m--) {
        int64_t defense, attack;
        cin >> defense >> attack;

        int pos = lower_bound(strength.begin(), strength.end(), defense, greater<int64_t>()) - strength.begin();

        if (pos >= n) {
            auto S = total - *strength.rbegin();
            cout << max(int64_t(0), attack - S) << '\n';
        } else {
            auto COST = max(int64_t(0), defense - strength[pos]);
            auto S = total - strength[pos];
            int64_t ans = COST + max(int64_t(0), attack - S);
            if (pos == 0) {
                cout << ans << '\n';
            } else {
                COST = max(int64_t(0), defense - strength[pos - 1]);
                S = total - strength[pos - 1];
                ans = min(ans, COST + max(int64_t(0), attack - S));
                cout << ans << '\n';
            }
        }
    }

    return 0;
}