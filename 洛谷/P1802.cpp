//记得乘1ll
//fixed别变成珂学计数
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
int n, x;
long long lose[MAXN], win[MAXN], use[MAXN];
long long dp[MAXN][MAXN];
void solve(){
	cin >> n >> x;
	for(int i = 1; i <= n; ++i)
		cin >> lose[i] >> win[i] >> use[i];
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= x; ++j){
			dp[i][j] = dp[i-1][j] + lose[i];;
			if(j >= use[i])
				dp[i][j] = max(dp[i-1][j] + lose[i], dp[i-1][j-use[i]] + win[i]);
		}
	}
	cout << 5ll*dp[n][x] << endl;
}
int main(){
	SYNC;
	solve();
}
