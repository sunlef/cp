//记得乘1ll
//别让小数变成珂学计数
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
set<int> s;
int ans[10];
void solve(){
	int cnt = 0;
	for(int i = 1; i <= 7; ++i){
		int t;
		cin >> t;
		if(s.count(t))
			++cnt;
	}
	++ans[cnt];
}
int main(){
	SYNC;
	cin >> n;
	for(int i = 1; i <= 7; ++i){
		int t;
		cin >> t;
		s.insert(t);
	}
	while(n--)
		solve();
	for(int i = 7; i >= 1; --i)
		cout << ans[i] << " ";
	cout << endl;
}
