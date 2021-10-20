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
const int MAXN = 214514;
int N, C;
int a[MAXN];
long long query(int x){
	return upper_bound(a+1, a+N+1, x+C) - lower_bound(a+1, a+N+1, x+C);
}
void solve(){
	cin >> N >> C;
	for(int i = 1; i <= N; ++i)
		cin >> a[i];
	sort(a+1, a+N+1);
	long long ans = 0;
	for(int i = 1; i <= N; ++i)
		ans += query(a[i]);
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}
