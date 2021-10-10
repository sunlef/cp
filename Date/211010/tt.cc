#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define endl '\n'
#define rep(i,a,b) for(int i=a; i<=b; i++) 
int dp[1000];
const int MOD = 111111;
int main() {
    memset(dp, 0, sizeof(dp));
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 1; i <= n; ++i)
	{
		s[i] = tolower(s[i]);
		dp[1] = (dp[1] + (s[i] == 'n')) % MOD;
		dp[2] = (dp[2] + (s[i] == 'u') * dp[1]) % MOD;
		dp[3] = (dp[3] + (s[i] == 'n') * dp[2]) % MOD;
		dp[4] = (dp[4] + (s[i] == 'h') * dp[3]) % MOD;
		dp[5] = (dp[5] + (s[i] == 'e') * dp[4]) % MOD;
		dp[6] = (dp[6] + (s[i] == 'h') * dp[5]) % MOD;
		dp[7] = (dp[7] + (s[i] == 'h') * dp[6]) % MOD;
		dp[8] = (dp[8] + (s[i] == 'e') * dp[7]) % MOD;
		dp[9] = (dp[9] + (s[i] == 'h') * dp[8]) % MOD;
	}
	cout << dp[9] << endl;
    return 0;
}