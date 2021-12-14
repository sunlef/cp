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
const int MAXN = 114514;
int n, m;
int a[MAXN];
void solve(){
	int ans = INF;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(i >= m){
			int res = 0;
			for(int j = 1; j <= m; ++j)
				res += a[i-m+j];
			ans = min(res, ans);
		}
	}
	if(n == 0 || m == 0){
		cout << 0 << endl;
		return;
	}
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}
