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
const int MAXN = 114514;
int T, M;
long long dp[120][1020];
int t[120], v[120];
void solve(){
	cin >> T >> M;
	for(int i = 1; i <= M; ++i)
		cin >> t[i] >> v[i];
	for(int i = 1; i <= M; ++i)
		for(int j = 0; j <= T; ++j){
			dp[i][j] = dp[i-1][j];
			if(j >= t[i])
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-t[i]] + v[i]);
		}
	cout << dp[M][T] << endl;
}
int main(){
	SYNC;
	solve();
}
