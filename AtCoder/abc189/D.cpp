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
bool op[MAXN];
int N;
long long dp[2][MAXN];
void solve(){
	cin >> N;
	for(int i = 1; i <= N; ++i){
		string tmp;
		cin >> tmp;
		if(tmp == "AND")
			op[i] = true;
		else
			op[i] = false;
	}
	dp[1][0] = dp[0][0] = 1;
	for(int i = 1; i <= N; ++i){
		if(op[i] == true){
			dp[0][i] = dp[1][i-1] + dp[0][i-1] * 2;
			dp[1][i] = dp[1][i-1];
		}
		else{
			dp[0][i] = dp[0][i-1];
			dp[1][i] = dp[1][i-1] * 2 + dp[0][i-1];
		}
	}
	cout << dp[1][N] << endl;
}
int main(){
	SYNC;
	solve();
}
