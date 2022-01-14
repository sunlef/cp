#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<int> cnt(26);
    ranges::for_each(S, [&](char ch) { cnt[ch - 'a']++; });

    array<int, 2> sum = {0, 0};
    ranges::for_each(cnt, [&](int X) {
        sum[0] += X / 2;
        sum[1] += X % 2;
    });

    int ans = sum[0] / K * 2 + (sum[1] + (sum[0] % K) * 2 >= K);
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