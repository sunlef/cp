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
const int MAXN = 11450;
int N;
int A[MAXN];
int L[MAXN], R[MAXN];
void solve(){
	cin >> N;
	A[0] = A[N+1] = -INF;
	for(int i = 1; i <= N; ++i)
		L[i] = R[i] = 0;
	for(int i = 1; i <= N; ++i)
		cin >> A[i];
	for(int i = 1; i <= N; ++i){
		int now_min = A[i];
		int nowl = i - 1;
		while(now_min <= A[nowl])
			nowl = L[nowl] - 1;
		L[i] = nowl + 1;
	}
	for(int i = N; i >= 1; --i){
		int now_min = A[i];
		int nowr = i + 1;
		while(now_min <= A[nowr])
			nowr = R[nowr] + 1;
		R[i] = nowr - 1;
	}
	int ans = -INF;
	for(int i = 1; i <= N; ++i){
		int now_ans = A[i] * (R[i] - L[i] + 1);
		ans = max(ans, now_ans);
	}
	cout << ans << endl;
}
int main(){
	SYNC;
	solve();
}
