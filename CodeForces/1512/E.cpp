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
int n, l, r, s;
int a[MAXN];
void solve(){
	cin >> n >> l >> r >> s;
	if(s > n || 2*s < (2+r-l)*(1+r-l)){
		cout << -1 << endl;
		return;
	}
	for(int i = 1; i <= n; ++i)
		a[i] = i;
	
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}
