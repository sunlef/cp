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
const int MAXN = 1145;
long long sum[MAXN][MAXN];
int n, m;
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			int tmp;
			cin >> tmp;
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + tmp;
		}
	int minn, minm, minx = INF;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(abs(2*sum[i][j]  - sum[n][m]) < minx){
				minn = i;
				minm = j;
				minx = abs(2*sum[i][j]  - sum[n][m]);
			}
	cout << minn << " " << minm << endl;
}
int main(){
	SYNC;
	solve();
}
