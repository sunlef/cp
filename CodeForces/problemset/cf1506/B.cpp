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
char ch;
int n, k;
bool a[60];	//true : *
			//false : .
void solve(){
	cin >> n >> k;
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		cin >> ch;
		a[i] = ch == '*' ? true : false;
		if(a[i])
			++cnt;
	}
	if(cnt <= 2){
		cout << cnt << endl;
		return;
	}
	int ans = 2;
	int l = 1, r = n;
	while(!a[l])
		++l;
	while(!a[r])
		--r;
	int last_replace = l;
	int last_find;
	for(int i = l+1; i < r; ++i){
		if(i-last_replace >= k){
			if(a[i]){
				++ans;
				last_replace = i;
			}
			else{
				++ans;
				last_replace = last_find;
			}
		}
		else if(a[i])
			last_find = i;
	}
	cout << ans << endl;
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}
