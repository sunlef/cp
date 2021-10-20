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
int ans[MAXN];
int n;
int a;
void solve(){
	int cnt1 = 0, cnt2 = MAXN;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a;
		if(a % 2 == 0)
			ans[--cnt2] = a;
		else
			ans[++cnt1] = a;
	}
	for(int i = 1; i <= cnt1; ++i){
		cout << ans[i] << " ";
	}
	for(int i = MAXN-1; i >= cnt2; --i){
		cout << ans[i] << " ";
	}
	cout << endl;
}
int main(){
	SYNC;
	int t;
	cin >> t;
	while(t--)
		solve();
}
