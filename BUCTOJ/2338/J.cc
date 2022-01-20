#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    while (cin >> S >> N) {
        vector<int> A(N);
        for (int &i : A) {
            cin >> i;
        }

        vector<int> dp(S + 1);
        for (int i = 0; i < N; ++i) {
            for (int j = S; j >= A[i]; --j) {
                dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
            }
        }

        cout << (dp[S] == S ? "YES\n" : "NO\n");
    }

    return 0;
}