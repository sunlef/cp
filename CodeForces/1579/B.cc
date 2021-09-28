#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1), pos(n + 1);
    vector<pair<int, int>> aa(n);

    for (int i = 0; i < n; ++i) {
        cin >> aa[i].first;
        aa[i].second = i + 1;
    }

    sort(aa.begin(), aa.end());

    for (int i = 0; i < n; ++i) {
        a[aa[i].second] = i + 1;
    }
    for (int i = 1; i <= n; ++i) {
        pos[a[i]] = i;
    }


    vector<tuple<int, int, int>> ans;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != i) {
            auto tmp = a;
            int l = i, r = pos[i], d = r - l;
            ans.push_back({l, r, d});
            for (int j = l; j <= r; ++j) {
                if (j + d <= r) {
                    tmp[j] = a[j + d];
                } else {
                    tmp[j] = a[l - r + d + j - 1];
                }
            }
            a = tmp;
            for (int j = l; j <= r; ++j) {
                pos[a[j]] = j;
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto &[l, r, d] : ans) {
        cout << l << ' ' << r << ' ' << d << '\n';
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