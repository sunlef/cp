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
const int MAXN = 1145140;
long long x[MAXN];
long long n, m, q;
long long p, k;
long long ans;
void solve(){
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++i)
		cin >> x[i];
	while(q--){
		cin >> p >> k;
		long long s = x[k]*p;
		if(s <= m)
			ans = s;
		else{
			if(s/m&1)
				ans = m-(s-m*(s/m));
			else
				ans = s-m*(s/m);
		}
		cout << ans << endl;
	}
}
int main(){
	SYNC;
	solve();
}
