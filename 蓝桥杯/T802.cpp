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
int xA, yA, xB, yB, L;
int x1, y1, x2, y2, x3, y3;
int minx, miny, maxx, maxy;
void solve(){
	cin >> xA >> yA >> xB >> yB >> L;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	minx = min(x1, min(x2, x3));
	miny = min(y1, min(y2, y3));
	maxx = max(x1, max(x2, x3));
	maxy = max(y1, max(y2, y3));
	
}
int main(){
	SYNC;
	solve();
}
