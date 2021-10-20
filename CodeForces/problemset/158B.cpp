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
int s[5], tmp, ans;
void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> tmp;
		++s[tmp];
	}
	ans = s[4];
	int p13 = min(s[1], s[3]);
	ans += p13;
	s[1] -= p13;
	s[3] -= p13;
	ans += s[3];
	int p2 = s[2] / 2;
	ans += p2;
	s[2] -= 2*p2;
	if(s[2]){
		if(s[1] >= 2){
			++ans;
			s[1] -= 2;
		}
		else if(s[1] == 1){
			s[1] = 0;
			++ans;
		}
		else
			++ans;
	}
	int p1 = s[1] / 4;
	ans += p1;
	s[1] -= 4*p1;
	if(s[1])
		++ans;
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}
