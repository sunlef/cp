//记得乘1ll
//别让小数变成珂学计数
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
int r;
int m[MAXN][MAXN];
long long dp[MAXN][MAXN];
void solve(){
	cin >> r;
	for(int i = 1; i <= r; ++i)
		for(int j = 1; j <= i; ++j)
			cin >> m[i][j];
	for(int i = r; i >= 1; --i)
		for(int j = 1; j <= i; ++j)
			dp[i][j] = 1ll*m[i][j] + 1ll*max(dp[i+1][j], dp[i+1][j+1]);
	cout << dp[1][1] << endl;
}
int main(){
	SYNC;
	solve();
}
