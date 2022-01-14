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
int n, _n;
void solve(){
	cin >> n;
	_n = n;
	int tmp;
	int jigecnt = 0, youxiucnt = 0;
	while(_n--){
		cin >> tmp;
		if(tmp >= 85)
			++youxiucnt;
		if(tmp >= 60)
			++jigecnt;
	}
	double ansa = jigecnt * 100.0/ n;
	double ansb = youxiucnt * 100.0/ n;
	printf("%d%c\n%d%c\n", (int)(ansa+0.5), '%', (int)(ansb+0.5), '%');
}
int main(){
//	SYNC;
	solve();
}
