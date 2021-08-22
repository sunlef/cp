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
const int MAXN = 2021;
int pre[MAXN];
int n;
void solve(){
	cin >> n;
	int res = 0;
	for(int i = 1; i <= n; ++i){
		cin >> pre[i];
		res ^= pre[i];
		pre[i] ^= pre[i-1];
	}
	if(res == 0){
		cout << "YES" << endl;
		return;
	}
	for(int i = 1; i < n - 1; ++i)
		for(int j = i+1; j < n; ++j){
			if(pre[i] == (pre[j]^pre[i]) && pre[i] == (pre[n]^pre[j])){
				cout << "YES" << endl;
				return;
			}
		}
	cout << "NO" << endl;
}
int main(){
	SYNC;
	int t;
	cin >> t;
	while(t--)
		solve();
}
