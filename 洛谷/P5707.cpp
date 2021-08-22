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
int s, v;
void solve(){
	cin >> s >> v;
	double t = (1.0*s/v)+10;
	int t1 = t;
	if(t > t1)
		++t1;
	int h = 8, m = 0;
	for(int i = 1; i <= t1; ++i){
		--m;
		if(m == -1){
			m = 59;
			h--;
		}
		if(h == -1){
			h = 23;
		}
	}
	if(h<10)
		cout << 0 << h;
	else
		cout << h;
	cout << ":";
	if(m<10)
		cout << 0 << m;
	else
		cout << m;
	cout << endl;
}
int main(){
	SYNC;
	solve();
}
