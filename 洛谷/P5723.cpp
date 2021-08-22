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
bool prime(int x){
	if(x <= 1)
		return false;
	for(int i = 2; i <= sqrt(x); ++i)
		if(x%i == 0)
			return false;
	return true;
}
void solve(){
	int L, cnt = 0, now = 0;
	cin >> L;
	int a[MAXN];
	for(int i = 2; i <= 1e5; ++i){
		if(prime(i)){
			a[++cnt] = i;
			now += i;
			if(now > L){
				now -= i;
				--cnt;
				break;
			}
		}
	}
	for(int i = 1; i <= cnt; ++i)
		cout << a[i] << endl;
	cout << cnt << endl;
}
int main(){
	SYNC;
	solve();
}
