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
#define MYTYPE int
using namespace std;
#define MAXN 300010
MYTYPE read(){
	MYTYPE x = 0, w = 1;
	char ch = 0;
	while(ch < '0' || ch > '9'){
		if(ch == '-')
			w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = 10 * x + ch - '0';
		ch = getchar();
	}
	return x * w;
}
int a[MAXN];
void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	for(int i = 2; i <= n - 1; ++i)
		if((a[i] > a[i+1] && a[i] > a[i-1]) || (a[i] < a[i+1] && a[i] < a[i-1]))
			++ans;
	cout << ans << endl;
}
int main(){
	SYNC;
	int t;
	cin >> t;
	while(t--)
		solve();
}