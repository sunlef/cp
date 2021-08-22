#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
#define SYNC ios::sync_with_stdio(0),cin.tie(0)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define EPS 1e-6
#define endl '\n'
using namespace std;
const int MAXN = 1145;
const int MOD = 1000007;
int N, K;
int a[MAXN];
int dp[MAXN][MAXN];
void solve(){
	cin >> N >> K;
	for(int i = 1; i <= N; ++i){
		cin >> a[i];
		dp[i][1] = 1;
	}
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= K; ++j)
			for(int k = 1; k <= i; ++k)
				if(a[k] < a[i])
					dp[i][j] += dp[k][j-1];
	int ans = 0;
	for(int i = 1; i <= N; ++i)
		ans = (ans + dp[i][K]) % MOD;
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}
