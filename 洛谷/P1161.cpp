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
const int MAXN = 2e6+10;
bool l[MAXN];
double a;
int t;
void solve(){
	int n;
	cin >> n;
	while(n--){
		cin >> a >> t;
		for(int i = 1; i <= t; ++i)
			l[(int)(a*i)] = !l[(int)(a*i)];
	}
	for(int i = 1; i <= MAXN-10; ++i)
		if(l[i]){
			cout << i << endl;
			return;
		}
}
int main(){
	SYNC;
	solve();
}
