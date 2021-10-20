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
const int MAXN = 30;
int N, M;
int A, B;
vector<int> G[MAXN];
int color[MAXN];
int ans;
inline bool can(int u){
	for(auto v : G[u])
		if(color[v] == color[u])
			return false;
	return true;
}
void dfs(int step){
	if(step == N+1){
	/*	for(int i = 1; i <= N; ++i)
			cout << color[i];
		cout << endl;*/
		++ans;
		return;
	}
	for(int i = 1; i <= 3; ++i){
		color[step] = i;
		if(can(step)){
			dfs(step + 1);
			color[step+1] = 0;
		}
	}
}
void solve(){
	cin >> N >> M;
	cout << std::fixed;
	cout.precision(0);
	if(M == 0){
		cout << pow(3,N) << endl;
		return;
	}
	else if(M == 1 && N != 1){
		cout << 2*pow(3,N-1) << endl;
		return;
	}
	for(int i = 1; i <= M; ++i){
		cin >> A >> B;
		G[A].push_back(B);
		G[B].push_back(A);
	}
	dfs(1);
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}

