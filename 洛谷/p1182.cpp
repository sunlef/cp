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
long long N, M;
long long A[MAXN];
bool check(long long x){
	//M段，M-1个挡板
	int res = 0;
	long long now = 0;
	for(long long i = 1; i <= N; ++i){
		now += A[i];
		if(now > x){
			now = A[i];
			++res;
		}
	}
	return res <= M-1;
}
void solve(){
	cin >> N >> M;
	long long maxx = -INF;
	for(int i = 1; i <= N; ++i){
		cin >> A[i];
		maxx = max(A[i], maxx);
	}
	long long l = maxx, r = INF;
	while(l <= r){
		long long mid = l + (r-l >> 1);
		if(check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << l << endl;
}
int main(){
	SYNC;
	solve();
}
