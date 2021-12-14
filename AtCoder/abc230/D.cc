#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> a(n);
    for (auto &[l, r] : a) {
        cin >> l >> r;
    }

    sort(a.begin(), a.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) { return lhs.second < rhs.second; });

    int dl = -1, dr = -1;

    int ans = 0;
    for (auto [l, r] : a) {
        if ((dr < l) || (dl > r)) {
            ++ans;
            dl = r;
            dr = r + d - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
