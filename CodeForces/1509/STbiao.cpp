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
int a[MAXN];
int ans[MAXN][21];
int n, m;
int query(int l, int r){
	int k = log2(r-l+1);
	return max(ans[l][k], ans[r-(l<<k)+1][k]);
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> ans[i][0];
	for(int j = 1; j <= 21; ++j)
		for(int i = 1; i+(1<<j)-1 <= n; ++i)
			ans[i][j] = max(ans[i][j-1], ans[i+(1<<(j-1))][j-1]);
	for(int i = 1; i <= m; ++i){
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
}
int main(){
	SYNC;
	solve();
}
