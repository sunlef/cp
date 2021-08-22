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
const int MAXN = 1014;
int N, X;
int V[MAXN], P[MAXN];
void solve(){
	cin >> N >> X;
	X *= 100;
	for(int i = 1; i <= N; ++i)
		cin >> V[i] >> P[i];
	int now = 0;
	for(int i = 1; i <= N; ++i){
		now += V[i] * P[i];
		if(now > X){
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
}
int main(){
	SYNC;
	solve();
}
