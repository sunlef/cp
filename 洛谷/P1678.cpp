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
int a[MAXN], b;
int n, m;
void solve(){
	long long ans = 0;
	cin >> m >> n;
	for(int i = 1; i <= m; ++i)
		cin >> a[i];
	sort(a+1, a+m+1);
	for(int i = 1; i <= n; ++i){
		cin >> b;
		int p = upper_bound(a+1, a+m+1, b) - a;
		if(b <= a[1])
			ans += a[1] - b;
		else if(b >= a[m])
			ans += b - a[m];
		else
			ans += min(abs(a[p]-b), abs(a[p-1]-b));
	}
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}
