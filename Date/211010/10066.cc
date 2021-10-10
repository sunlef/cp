#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long pow(long long a, int p) {
    long long res = 1 % MOD;
    a %= MOD;

    while (p) {
        if (p & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
    }
    return res;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        vector<int> dp(10, 0);
        vector<int> cntpre(s.size(), 0);
        vector<int> cnta(s.size(), 0);
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                cnta[i] = cnta[i - 1];
            }
            if (s[i] == 'a') {
                ++cnta[i];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'n') {
                dp[3] += dp[2];
                ++dp[1];
            } else if (s[i] == 'u') {
                dp[2] += dp[1];
            } else if (s[i] == 'h') {
                dp[9] += dp[8];
                dp[7] += dp[6];
                dp[6] += dp[5];
                dp[4] += dp[3];
            } else if (s[i] == 'e') {
                dp[8] += dp[7];
                dp[5] += dp[4];
            }
            cntpre[i] = dp[9];
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long PRE;
            if (i > 0) {
                PRE = cntpre[i] - cntpre[i - 1];
            } else {
                PRE = cntpre[0];
            }
            long long SUB = cnta[n - 1] - cnta[i];
            long long POW = pow(2, SUB) - 1;
            if (POW < 0) {
                POW += MOD;
            }
            ans = (ans + (PRE * POW % MOD)) % MOD;
        }
        cout << ans << endl;
    }
}