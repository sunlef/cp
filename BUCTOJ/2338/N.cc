#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> denominations(M);
    for (int &i : denominations) {
        cin >> i;
    }

    sort(denominations.begin(), denominations.end());

    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;

    for (int i : denominations) {
        for (int j = 0; j + i <= N; ++j) {
            dp[j + i] = min(dp[j + i], dp[j] + 1);
        }
    }

    cout << dp[N] << '\n';

    return 0;
}