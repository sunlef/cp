//记得乘1ll
//fixed别变成珂学计数
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
const int MAXN = 514;
long long dp[MAXN][MAXN];
int MAi, MAj;
int Bi, Bj;
bool can_go(int i, int j){
	if(i == MAi - 2)
		return j != MAj - 1 && j != MAj + 1;
	if(i == MAi - 1)
		return j != MAj - 2 && j != MAj + 2;
	if(i == MAi)
		return j != MAj;
	if(i == MAi + 1)
		return j != MAj - 2 && j != MAj + 2;
	if(i == MAi + 2)
		return j != MAj - 1 && j != MAj + 1;
	return true;
}
void solve(){
	cin >> Bi >> Bj >> MAi >> MAj;
	dp[0][0] = 1;
	for(int i = 1; i <= Bi; ++i)
		if(can_go(i, 0))
			dp[i][0] = dp[i-1][0];
	for(int j = 1; j <= Bj; ++j)
		if(can_go(0, j))
			dp[0][j] = dp[0][j-1];
	for(int i = 1; i <= Bi; ++i)
		for(int j = 1; j <= Bj; ++j)
			if(can_go(i, j))
				dp[i][j] = dp[i][j-1] + dp[i-1][j];
	cout << dp[Bi][Bj] << endl;
}
int main(){
	SYNC;
	solve();
}
