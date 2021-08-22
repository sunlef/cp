//记得乘1ll
//fixed别变成珂学计数
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
const int MAXN = 34514;
int a[MAXN];
int d[MAXN];
int n, top;
void solve(){
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	d[1] = a[1];
	top = 1;
	for (int i = 2; i <= n; ++i){
		if(d[top] < a[i])
			d[++top] = a[i];
		else{
			int pos = lower_bound(d+1, d+top+1, a[i]) - d;
			d[pos] = a[i];
		}
	}
	cout << top << endl;
}
int main(){
	SYNC;
	while(cin >> n)
		solve();
}
