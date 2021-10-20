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
#include<ctime>
#define SYNC ios::sync_with_stdio(0),cin.tie(0)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define EPS 1e-6
#define endl '\n'
using namespace std;
const int MAXN = 114514;
void solve(){
	int n = MAXN;
	srand((int)time(0));
	freopen("ss.txt", "w", stdout);
	cout << n << endl;
	for(int i = 1; i <= n; ++i)
		cout << rand() % 1000000000 << " ";
}
int main(){
	SYNC;
	solve();
}
