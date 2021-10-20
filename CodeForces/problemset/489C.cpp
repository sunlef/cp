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
int m, _s, s;
int ans1[110];
int ans2[110];
void solve(){
	cin >> m >> _s;
	s = _s;
	if((s == 0 && m != 1)|| s > 9*m){
		cout << "-1 -1" << endl;
		return;
	}
	ans1[1] = 1;
	--s;
	ans1[m] += s;
	for(int i = m; i >= 1; --i){
		if(ans1[i] > 9){
			int d = ans1[i] - 9;
			ans1[i-1] += d;
			ans1[i] -= d;
		}
	}
	for(int i = 1; i <= m; ++i)
		cout << ans1[i];
	cout << " ";

	s = _s;
	ans2[1] = 1;
	s -= 1;
	ans2[1] += s;
	for(int i = 1; i <= m; ++i){
		if(ans2[i] > 9){
			int d = ans2[i] - 9;
			ans2[i+1] += d;
			ans2[i] -= d;
		}
	}
	for(int i = 1; i <= m; ++i)
		cout << ans2[i];
	cout << endl;
}
int main(){
	SYNC;
	solve();
}
