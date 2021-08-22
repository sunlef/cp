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
const int MAXN = 11451;
int head[100020], cnt;
struct edge{
	int u, v, w, nxt;
}e[MAXN];
void add(int a, int	b, int c){
	e[++cnt].u = a;
	e[cnt].v = b;
	e[cnt].w = c;
	e[cnt].nxt = head[a];
	head[a] = cnt;
}
int dis[MAXN];
bool visted[MAXN];
int s;
struct Node{
	int w, now;
}
void solve(){
	
}
int main(){
	SYNC;
	solve();
}
