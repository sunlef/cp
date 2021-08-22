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
const int MAXN = 214514;
int a[MAXN], b[MAXN];
int n;
long long sum;
void solve(){
	cin >> n;
	sum = 0;
	int maxx = -INF;
	int maxpos = 0;
	for(int i = 1; i <= n+2; ++i){
		cin >> b[i];
		sum += b[i];
		if(maxx < b[i]){
			maxx = b[i];
			maxpos = i;
		}
	}
	sum -= maxx;
	bool flag = false;
	for(int i = 1; i <= n+2; ++i){
		if(flag)
			break;
		if(i == maxpos)
			continue;
		if(sum - b[i] == maxx){
			flag = true;
			for(int j = 1; j <= n+2; ++j){
				if(j == i || j == maxpos)
					continue;
				cout << b[j] << " ";
			}
			cout << endl;
		}
	}
	if(!flag){
		sum += maxx;
		int lastmax = maxx;
		maxx = -INF;
		for(int i = 1; i <= n+2; ++i){
			if(b[i] > maxx && b[i] != lastmax){
				maxx = b[i];
				maxpos = i;
			}
		}
		sum -= maxx;
		flag = false;
		for(int i = 1; i <= n+2; ++i){
			if(flag)
				break;
			if(i == maxpos)
				continue;
			if(sum - b[i] == maxx){
				flag = true;
				for(int j = 1; j <= n+2; ++j){
					if(j == i || j == maxpos)
						continue;
					cout << b[j] << " ";
				}
				cout << endl;
			}
		}
	}
	if(!flag)
		cout << -1 << endl;
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}
