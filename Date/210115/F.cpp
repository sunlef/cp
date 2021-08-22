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
int n;
int A[MAXN], C;
bool check(int x){
	int cnt = 0;
	int j = 1;
	for(int i = 1; i <= n; ++i){
		while(j <= n && A[j] - A[i] <= x)
			++j;
		--j;
		cnt += j - i;
	}
	if(C % 2 == 0)
		return cnt < C / 2;
	else
		return cnt <= C / 2;
}
void solve(){
	for(int i = 1; i <= n; ++i)
		cin >> A[i];
	sort(A+1, A+n+1);
	C = n * (n-1) / 2;
	int l = 0, r = 1000000001; 
	while(l < r){
		int m = l+r >> 1;
		if(check(m))
			l = m + 1;
		else
			r = m;
	}
	cout << l << endl;
}
int main(){
	SYNC;
	while(cin >> n)
		solve();
}
