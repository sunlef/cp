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
const int MAXN = 110;
int n, k;
string s;
void solve(){
	cin >> n >> k;
	cin >> s;
	if(n < 2*k + 1){
		puts("NO");
		return;
	}
	for(int i = 0; i <= k-1; ++i){
		if(s[i] != s[n-i-1]){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main(){
	SYNC;
	int t;
	cin >> t;
	while(t--)
		solve();
}
