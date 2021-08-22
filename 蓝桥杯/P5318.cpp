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
const int MAXN = 100010;
vector<int> e[MAXN];
bool visted[MAXN];
int n, m;
void dfs(int u){
	visted[u] = true;
	cout << u << " ";
	for(auto i : e[u]){
		if(!visted[i])
			dfs(i);
	}
}
void solve(){
	cin >> n >> m;
	int u, v;
	for(int i = 1; i <= m; ++i){
		cin >> u >> v;
		e[u].push_back(v);
	}
	for(int i = 1; i <= n; ++i){
		sort(e[i].begin(), e[i].end());
	}
	dfs(1);
	cout << endl;
	memset(visted, 0, sizeof(visted));
	queue<int> q;
	q.push(1);
	visted[1] = true;
	while(!q.empty()){
		u = q.front();
		q.pop();
		cout << u << " ";
		for(auto i : e[u])
			if(!visted[i]){
				visted[i] = true;
				q.push(i);
			}
	}
	cout << endl;
}
int main(){
	SYNC;
	solve();
}
