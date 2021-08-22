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
long long N, K;
long long a[MAXN];
bool check(long long x){
	if(!x)
		return true;
	long long res = 0;
	for(int i = 1; i <= N; ++i)
		res += a[i]/x;
	return res >= K;
}
void solve(){
	cin >> N >> K;
	for(int i = 1; i <= N; ++i)
		cin >> a[i];
	long long l = 0, r = INF;
	while(l <= r){
		long long mid = l + (r-l >> 1);
		if(check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << l - 1 << endl;
}
int main(){
	SYNC;
	solve();
}
