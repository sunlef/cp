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
const int MAXN = 1014514;
int n, m, q;
int a[MAXN];
int query(int x){
	int l = 1, r = n+1;
	while(l < r){
	//	cout << x << " " << l << " " << r << endl;
		int mid = l + (r-l >> 1);
		if(a[mid] < x)
			l = mid + 1;
		else
			r = mid;
	}
	if(a[l] == x)
		return l;
	else
		return -1;
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= m; ++i){
		cin >> q;
		cout << query(q) << " ";
	}
	cout << endl;
}
int main(){
	SYNC;
	solve();
}
