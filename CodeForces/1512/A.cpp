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
int a[MAXN];
void solve(){
	cin >> n;
	int ans;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 2; i <= n; ++i){
		if(a[i] != a[i-1]){
			if(i == n){
				cout << n << endl;
				return;
			}
			else{
				if(a[i] == a[i+1]){
					cout << i-1 << endl;
					return;
				}
				else{
					cout << i << endl;
					return;
				}
			}
		}
	}
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}
