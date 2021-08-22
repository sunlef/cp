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
const int MAXN = 114;
int a[MAXN];
int n;
int cntodd, cnteven;
int posodd, poseven;
void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] % 2 == 0){
			++cnteven;
			poseven = i;
		}
		else{
			++cntodd;
			posodd = i;
		}
	}
	if(cntodd == 1)
		cout << posodd << endl;
	else
		cout << poseven << endl;
}
int main(){
	SYNC;
	solve();
}
