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
const int MAXN = 314514;
int n;
long long v[MAXN];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	sort(v+1, v+n+1);
	int pos0 = lower_bound(v+1, v+n+1, 0) - v;
	long long cur = v[n];
	for(int i = 1; i < pos0; ++i)
		cur -= v[i];
	if(pos0 != n){
		long long cur1 = v[pos0];
		for(int i = pos0+1; i < n; ++i)
			cur1 -= v[i];
		cur -= cur1;
	}
	cout << cur << endl;
}
int main(){
	SYNC;
	solve();
}
