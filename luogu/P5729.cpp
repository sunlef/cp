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
bool m[MAXN][MAXN][MAXN];
int ans;
int w, x, h;
int q;
int xa, ya, za;
int xb, yb, zb;
void solve(){
	cin >> w >> x >> h;
	for(int i = 1; i <= w; ++i)
		for(int j = 1; j <= x; ++j)
			for(int k = 1; k <= h; ++k)
				m[i][j][k] = true;
	ans = w*x*h;
	cin >> q;
	while(q--){
		cin >> xa >> ya >> za >> xb >> yb >> zb;
		for(int i = xa; i <= xb; ++i)
			for(int j = ya; j <= yb; ++j)
				for(int k = za; k <= zb; ++k){
					if(m[i][j][k]){
						--ans;
						m[i][j][k] = false;
					}
				}
	}
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}
