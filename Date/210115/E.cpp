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
const int MAXN = 4514;
int ab[MAXN*MAXN], cd[MAXN*MAXN];
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			ab[++cnt] = a[i] + b[j];
			cd[cnt] = c[i] + d[j];
		}
	sort(cd + 1, cd + cnt + 1);
	int ans = 0;
	for(int i = 1; i <= cnt; ++i){
		int r = upper_bound(cd + 1, cd + cnt + 1, -ab[i]) - cd;
		int l = lower_bound(cd + 1, cd + cnt + 1, -ab[i]) - cd;
		ans += r - l;
	}
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}
