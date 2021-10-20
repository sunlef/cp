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
int ans;
string a, b;
bool f(int al, int ar, int bl, int br){
	int len = a.size()-1-ar-al;
	for(int i = 0; i <= len; ++i)
		if(a[al+i] != b[bl+i])
			return false;
	return true;
}
bool can(int ai, int bi){
	for(int al = 0; al <= ai; ++al)
		for(int bl = 0; bl <= bi; ++bl)
			if(f(al,ai-al,bl,bi-bl))
				return true;
	return false;
}
void solve(){
	cin >> a >> b;
	ans = a.size() + b.size();
	if(a == b){
		cout << 0 << endl;
		return;
	}
	for(int ai = a.size()-1; ai >= 0; --ai)
		for(int bi = b.size()-1; bi >= 0; --bi){
			if(a.size() - ai != b.size() - bi)
				continue;
			if(can(ai, bi))
				ans = ai+bi;
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
