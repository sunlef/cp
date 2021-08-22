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
int R, C;
int m[MAXN][MAXN];
int visted[MAXN][MAXN];
bool can_go(int i0, int j0, int i1, int j1){
	if(i1 <= 0 || j1 <= 0 || i1 > R || j1 > C)
		return false;
	return m[i0][j0] > m[i1][j1];
}
int dfs(int i, int j){
	if(visted[i][j])
		return visted[i][j];
	int maxx = 0;
	if(can_go(i, j, i+1, j))
		maxx = max(maxx, dfs(i+1, j));
	if(can_go(i, j, i-1, j))
		maxx = max(maxx, dfs(i-1, j));
	if(can_go(i, j, i, j+1))
		maxx = max(maxx, dfs(i, j+1));
	if(can_go(i, j, i, j-1))
		maxx = max(maxx, dfs(i, j-1));
	return visted[i][j] = maxx + 1;
}
void solve(){
	cin >> R >> C;
	for(int i = 1; i <= R; ++i)
		for(int j = 1; j <= C; ++j)
			cin >> m[i][j];
	int ans = -INF;
	for(int i = 1; i <= R; ++i)
		for(int j = 1; j <= C; ++j)
			ans = max(ans, dfs(i,j));
	cout << ans << endl;
	
}
int main(){
	SYNC;
	solve();
}
