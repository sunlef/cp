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
#define MOD 1000000007
string A, B;
int dp[1010];
void solve(){
	memset(dp, 0, sizeof(dp) );
	for(int i = 0; i < A.size(); ++i)
		for(int j = B.size()-1; j >= 0; --j){
			if(A[i] == B[j]){
				if(j == 0)
					dp[j]++;
				else
					dp[j] += dp[j-1];
				dp[j] %= MOD;
			}
		}
	cout << dp[B.size()-1] << endl;
}
int main(){
	SYNC;
	while(cin >> A >> B)
		solve();
}
