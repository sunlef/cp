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
const int MAXN = 114;
int m[MAXN][MAXN];
int visted[MAXN][MAXN];	
int n, k;
int ans;
bool can_go(int i0, int j0, int i1, int j1){
	if(i1 <= 0 || j1 <= 0 || i1 > n || j1 > n)
		return false;
	return m[i0][j0] < m[i1][j1];
}
int dfs(int i, int j){
	if(visted[i][j])
		return visted[i][j];
	int maxx = 0;
	for(int s = 1; s <= k; ++s){
		if(can_go(i, j, i, j+s))
			maxx = max(maxx, dfs(i,j+s));
		if(can_go(i, j, i, j-s))
			maxx = max(maxx, dfs(i,j-s));
		if(can_go(i, j, i+s, j))
			maxx = max(maxx, dfs(i+s,j));
		if(can_go(i, j, i-s, j))
			maxx = max(maxx, dfs(i-s,j));
	}
	return visted[i][j] = m[i][j] + maxx;	
}
void solve(){
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			visted[i][j] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> m[i][j];
	cout << dfs(1,1) << endl;
}
int main(){
	SYNC;
	while(cin >> n >> k){
		if(n == k && n == -1)
			break;
		solve();
	}
}
