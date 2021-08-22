//记得乘1ll
//别让小数变成珂学计数
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
int N;
int A[MAXN], B[MAXN];
bool check(int x){
	for(int i = 1; i <= N; ++i)
		if(x < A[i] || x > B[i])
			return false;
	return true;
}	
void solve(){
	cin >> N;
	int minn = INF;
	for(int i =1 ; i <= N; ++i){
		cin >> A[i];
		minn = min(minn, A[i]);
	}
	int maxx = -INF;
	for(int i = 1; i <= N; ++i){
		cin >> B[i];
		maxx = max(maxx, B[i]);
	}
	int ans = 0;
	for(int i = minn; i <= maxx; ++i)
		if(check(i)){
			++ans;
		}
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}
