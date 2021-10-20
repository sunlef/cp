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
long long n, m, a;
long long h, s;
void solve(){
	cin >> n >> m >> a;
	if(n%a == 0)
		h = n / a;
	else
		h = n / a + 1;
	if(m%a == 0)
		s = m / a;
	else
		s = m / a + 1;
	cout << h*s << endl;
}
int main(){
	SYNC;
	solve();
}
