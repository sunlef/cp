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
int mm[MAXN][MAXN];
int ans[MAXN][MAXN];
void solve(){
	memset(mm, 0, sizeof(mm));
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> mm[i][j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			int maxx = -INF;
			for(int k = -1; k <= 1; ++k)
				for(int l = -1; l <= 1; ++l)
					maxx = max(maxx, mm[i+k][j+l]);
			ans[i][j] = maxx;
		}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}
int main(){
	SYNC;
	solve();
}
