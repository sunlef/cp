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
const int MAXN = 2000114;
int n, m;
int q;
int a[MAXN];
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	while(m--){
		cin >> q;
		cout << a[q] << endl;
	}
}
int main(){
	SYNC;
	solve();
}
