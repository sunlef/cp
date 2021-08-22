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
const int MAXN = 24;
int N;
vector<int> G[MAXN];
int a[MAXN];
int visted[MAXN];
int dfs(int u){
	if(visted[u])
		return visted[u];
	int maxx = 0;
	for(auto v : G[u]){
		maxx = max(maxx, dfs(v));
	return visted[u] = a[u] + maxx;
}
void solve(){
	cin >> N;
	for(int i = 1; i <= N; ++i)
		cin >> a[i];
	for(int i = 1; i <= N-1; ++i)
		for(int j = i+1; j <= N; ++j){
			bool t;
			cin >> t;
			if(t)
				G[i].push_back(j);
		}
	int ans = -INF;
	int ansi = -1;
	for(int i = 1; i <= N; ++i){
		int t = dfs(i);
		if(ans < dfs(i))
		ans = max(ans, dfs(i));
	}
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}
