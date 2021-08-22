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
int n, a[4];
int dp[4444];
void solve(){
	cin >> n >> a[1] >> a[2] >> a[3];
	dp[0] = 0;
	for(int i = 1; i <= n; ++i)
		dp[i] = -INF;
	for(int i = 0; i <= n; ++i)
		for(int j = 1; j <= 3; ++j)
			if(i >= a[j])
				dp[i] = max(dp[i], dp[i-a[j]] + 1);
	cout << dp[n] << endl;
}
int main(){
	SYNC;
	solve();
}
