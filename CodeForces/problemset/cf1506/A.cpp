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
long long n, m, x;
void solve(){
	cin >> n >> m >> x;
	int q1 = x / n;
	int q2 = x % n;
	if(q2 == 0)
		q2 = n;
	else
		q1 += 1;
	//cout << q1 << " " << q2 << endl;
	long long ans = m * (q2 - 1);
	ans += q1;
	cout << ans << endl;
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}
