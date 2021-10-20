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
vector<int> e[MAXN];
int n, m, u, v;
int ans[MAXN];
void dfs(int u, int v){
	if(ans[v])
		return;
	ans[v] = u;
	for(auto i : e[v])
		dfs(u, i);
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		cin >> u >> v;
		e[v].push_back(u);
	}
	for(int i = n; i >= 1; --i)
		dfs(i, i);
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << endl;
}
int main(){
	SYNC;
	solve();
}
