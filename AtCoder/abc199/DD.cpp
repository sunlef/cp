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
int dp[MAXN][5];
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
	dp[1][1] = dp[1][2] = dp[1][3] = 1;
	for(int i = 2; i <= N; ++i){
		for(auto v : G[i]){
			dp[i][1] = dp[v][2] + dp[v][3];
			dp[i][2] = dp[v][1] + dp[v][3];
			dp[i][3] = dp[v][1] + dp[v][2];
		}
	}
	cout << dp[N][1] + dp[N][2] + dp[N][3] << endl;
}
int main(){
	SYNC;
	solve();
}
