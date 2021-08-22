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
const int MAXN = 111514;
struct Node{
	int val, step;
}u, v;
int n, m;
bool visted[MAXN];
queue<Node> q;
void solve(){
	cin >> n >> m;
	memset(visted, false, sizeof(visted));
	u.val = n;
	u.step = 0;
	visted[n] = true;
	q.push(u);
	while(!q.empty()){
		u = q.front();
		if(u.val == m){
			cout << u.step << endl;
			return;
		}
		q.pop();
		v.step = u.step + 1;
		v.val = 2*u.val;
		if(v.val >= 0 && v.val < MAXN && !visted[v.val]){
			visted[v.val] = true;
			q.push(v);
		}
		v.val = u.val - 1;
		if(v.val >= 0 && v.val < MAXN && !visted[v.val]){
			visted[v.val] = true;
			q.push(v);
		}
	}
}
int main(){
	SYNC;
	solve();
}
