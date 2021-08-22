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
const int MAXN = 21451;
int a, b;
void solve(){
	cin >> a >> b;
	int ans = 0;
	if(a < b){
		if(b - a > 10){
			ans += (b-a) / 10;
			a += ans * 10;
		}
		if(a != b)
			ans++;
		cout << ans << endl;
		return;
	}
	if(a - b > 10){
		ans += (a - b) / 10;
		a -= ans * 10;
	}
	if(a != b)
		++ans;
	cout << ans << endl;
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}
