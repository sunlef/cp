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
bool a[MAXN];
int cnt1, cnt2;
void solve(){
	cin >> n;
	char ch;
	cnt1 = cnt2 = 0;
	for(int i = 1; i <= n; ++i){
		cin >> ch;
		a[i] = ch == 'T';
	}
	for(int i = 1; i <= n; ++i){
		if(a[i])
			++cnt1;
		else
			--cnt1;
		if(cnt1 < 0)
			break;
	}
	for(int i = n; i >= 1; --i){
		if(a[i])
			++cnt2;
		else
			--cnt2;
		if(cnt2 < 0)
			break;
	}
	if(cnt1 == cnt2 && 3*cnt1 == n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
int main(){
	SYNC;
	int t;
	cin >> t;
	while(t--)
		solve();
}
