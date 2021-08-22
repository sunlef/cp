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
const int MAXN = 114514;
int M, N;
int ans[10];
void work(int x){
	while(x){
		++ans[x%10];
		x /= 10;
	}
}
void solve(){
	cin >> M >> N;
	for(int i = M; i <= N; ++i)
		work(i);
	for(int i = 0; i <= 9; ++i)
		cout << ans[i] << " ";
	cout << endl;
}
int main(){
	SYNC;
	solve();
}
