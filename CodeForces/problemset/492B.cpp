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
#define EPS 1e-10
#define endl '\n'
using namespace std;
const int MAXN = 1050;
int n, l;
int a[MAXN];
bool check(double x){
	for(int i = 1; i <= n; ++i){
		if(i == 1){
			if(a[i] - x > 0)
				return false;
		}
		else if(a[i-1] + x < a[i] - x)
				return false;
		if(i == n)
			if(a[i] + x < l)
				return false;
	}
	return true;
}
void solve(){
	cin >> n >> l;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a+1, a+n+1);
	double l = 0, r = 1000000000;
	for(int i = 1; i <= 80; ++i){
		double mid = (l+r) / 2;
		if(check(mid))
			r = mid;
		else
			l = mid;
	}
	printf("%.10f\n", l);
}
int main(){
	SYNC;
	solve();
}
