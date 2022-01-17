#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> K(N), H(N);
    for (int &i : K) {
        cin >> i;
    }
    for (int &i : H) {
        cin >> i;
    }

    vector<pair<int64_t, int64_t>> manas;

    int l = -1, r = -1;
    for (int i = N - 1; i >= 0; --i) {
        if (l <= K[i] && K[i] <= r) {
            if (H[i] <= K[i] - l + 1) {
                continue;
            } else {
                l = K[i] - H[i] + 1;
            }
        } else {
            if (l != -1) {
                manas.push_back({l, r});
            }
            r = K[i];
            l = K[i] - H[i] + 1;
        }
    }

    if (l != -1) {
        manas.push_back({l, r});
    }

    int64_t ans = 0;
    for (auto [a, b] : manas) {
        int64_t len = b - a + 1;
        ans += (len + 1 ) * len / 2;
    }
    cout << ans << '\n';
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