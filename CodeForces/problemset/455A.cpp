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
int n;
int a[MAXN];
long long dp[MAXN];
void solve(){
	cin >> n;
	int maxx = -INF;
	for(int i = 1; i <= n; ++i){
		int t;
		cin >> t;
		a[t]++;
		maxx = max(maxx, t);
	}
	dp[1] = a[1];
	for(int i = 2; i <= maxx; ++i){
		dp[i] = max(dp[i-2] + 1ll*i*a[i], dp[i-1]);
	}
	cout << dp[maxx] << endl;
}
int main(){
	SYNC;
	solve();
}
