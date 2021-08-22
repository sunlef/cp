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
int N;
long long a[MAXN], b[MAXN];
long long ans[MAXN];
int maxa[MAXN], maxb[MAXN];
void solve(){
	cin >> N;
	int maxx = -INF;
	for(int i = 1; i <= N; ++i){
		cin >> a[i];
		if(a[i] > maxx){
			maxx = a[i];
			maxa[i] = i;
		}
		else
			maxa[i] = maxa[i-1];
	}
	maxx = -INF;
	for(int i = 1; i <= N; ++i){
		cin >> b[i];
		if(b[i] > maxx){
			maxx = b[i];
			maxb[i] = i;
		}
		else
			maxb[i] = maxb[i-1];
	}
	for(int i = 1; i <= N; ++i)
		ans[i] = a[maxa[i]] * b[i];
	for(int i = 1; i <= N; ++i)
		cout << ans[i] << endl;
}
int main(){
	SYNC;
	solve();
}
