#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int64_t> cnt(n + 1), ans(n + 1, INT_MAX);
    for (int i = 0; i < n; ++i) {
        int64_t x;
        cin >> x;
        ++cnt[x];
    }

    vector<int> pos;
    int64_t moves = 0;

    for (int MEX = 0; MEX <= n; ++MEX) {
        ans[MEX] = moves + cnt[MEX];
        if (cnt[MEX] == 0) {
            if (pos.empty()) 
                break;
            else {
                moves += MEX - pos.back();
                pos.pop_back();
            }
        }
        for (int i = 2; i <= cnt[MEX]; ++i) 
            pos.push_back(MEX);
    }

    for (int i = 0; i <= n; ++i)
        cout << (ans[i] == INT_MAX ? -1 : ans[i]) << " \n"[i == n];
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