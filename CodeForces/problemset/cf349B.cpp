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
const int MAXN = 1145140;
int v;
int a[10];
int ans[MAXN];
void solve(){
	cin >> v;
	int minn = INF;
	for(int i = 1; i <= 9; ++i){
		cin >> a[i];
		minn = min(minn, a[i]);
	}
	if(minn > v){
		puts("-1");
		return;
	}
	int max_bit = v / minn;
	int o;
	for(int i = 9; i >= 1; --i)
		if(a[i] == minn){
			o = i;
			break;
		}
	for(int i = 1; i <= max_bit; ++i)
		ans[i] = o;
	v -= max_bit*minn;
	for(int i = 1; i <= max_bit; ++i)
		for(int j = 9; j >= 1; --j){
			if(v + minn - a[j] >= 0){
				ans[i] = j;
				v = v + minn - a[j];
				break;
			}
		}
	for(int i = 1; i <= max_bit; ++i)
		cout << ans[i];
	puts("");
}
int main(){
	SYNC;
	solve();
}
