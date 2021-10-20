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
const int MAXN = 10000014;
int T, M;
long long t, v;
long long dp[MAXN];
void solve(){
	cin >> T >> M;
	for(int i = 1; i <= M; ++i){
		cin >> t >> v;
		for(int j = 0; j <= T; ++j)
			if(j >= t)
				dp[j] = max(dp[j], dp[j-t] + v);
	}
	cout << dp[T] << endl;
}
int main(){
	SYNC;
	solve();
}
