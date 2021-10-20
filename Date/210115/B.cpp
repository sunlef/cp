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
int n;
long long h[MAXN];
int L[MAXN], R[MAXN];
void solve(){
	for(int i = 1; i <= n; ++i)
		cin >> h[i];
	for(int i = 1; i <= n; ++i){
		int now_min = h[i];
		int nowl = i - 1;
		while(now_min <= h[nowl])
			nowl = L[nowl] - 1;
		L[i] = nowl + 1;
	}
	for(int i = n; i >= 1; --i){
		int now_min = h[i];
		int nowr = i + 1;
		while(now_min <= h[nowr])
			nowr = R[nowr] + 1;
		R[i] = nowr - 1;
	}
	long long ans = -INF;
	for(int i = 1; i <= n; ++i){
		long long now_ans = h[i] * (R[i] - L[i] + 1);
		if(now_ans > ans)
			ans = now_ans;
	}
	cout << ans << endl;
}
int main(){
	SYNC;
	while(cin >> n){
		if(n == 0)
			break;
		h[0] = h[n+1] = -INF;
		for(int i = 1; i <= n; ++i)
			L[i] = R[i] = 0;
		solve();
	}
}
