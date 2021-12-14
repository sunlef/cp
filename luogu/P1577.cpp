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
const int MAXN = 11514;
int N, K;
double L[MAXN];
bool check(double x){
	if(x == 0)
		return true;
	long long res = 0;
	for(int i = 1; i <= N; ++i)
		res += (int)(L[i]/x);
	return res >= K;
}
void solve(){
	cin >> N >> K;
	for(int i = 1; i <= N; ++i)
		cin >> L[i];
	double l = 0, r = INF;
	while(r-l > EPS){
		double mid = (l+r) / 2;
		if(check(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l << endl;
}
int main(){
	SYNC;
	solve();
}
