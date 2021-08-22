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
const int MAXN = 1145;
long long a[MAXN];
long long v, p;
void solve(){
	cin >> v >> p;
	a[1] = v;
	cout << 1 << " " << v << endl;
	for(int i = 2; i <= 100; ++i){
		a[i] = p % a[i-1];
		cout << i << " " << a[i] << endl;
		if(a[i] == 0)
			break;
	}
	
}
int main(){
	SYNC;
	solve();
}
