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
int n, k;
bool check(int x){
	if(x * n == k)
		return true;
	if(x * n < k)
		return false;
	int tmp = x * n;
	int cnt = tmp / k;
	int d = tmp - cnt * k;
	return d <= (x-1) * n;
}
void solve(){
	cin >> n >> k;
	for(int i = 1; i <= INF; ++i){
		if(
	}
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}
