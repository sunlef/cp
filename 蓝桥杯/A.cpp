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
void solve(){
	int t;
	cin >> n;
	bool flag = false;
	for(int i = 1; i <= n; ++i){
		cin >> t;
		if(!s.count(t))
			flag = true;
	}
	cout << (flag ? "Yes" : "No") << endl;
}
int main(){
	SYNC;
	int T;
	cin >> T;
	for(int i = 1; i <= 100; ++i)
		s.insert(i*i);
	while(T--)
		solve();
}
