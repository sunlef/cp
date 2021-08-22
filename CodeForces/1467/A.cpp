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
#define MAXN 200010
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
void solve(){
	int n;
	cin >> n;
	int dis = 10;
	while(n--){
		cout << abs(--dis);
		if(dis == -9)
			dis = 1;
	}
	cout << endl;
}
int main(){
	SYNC;
	int t;
	cin >> t;
	while(t--)
		solve();
}