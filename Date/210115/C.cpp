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
int n, x, y;
void solve(){
	cin >> n >> x >> y;
	int d = -1;
	for(int i = 1; i <= y-x; ++i)
		if((y-x) % i == 0 && (y-x) / i + 1 <= n){
			d = i;
			break;
		}
	int h = (y-x) / d + (x - 1) / d + 1; 
	if(h >= n){
		for(int i = 1; i <= n; ++i){
			cout << y << " ";
			y -= d;
		}
	}
	else{
		int _y = y;
		for(int i = 1; i <= h; ++i){
			cout << _y << " ";
			_y -= d;
		}
		_y = y;
		for(int i = 1; i <= n - h; ++i){
			_y += d;
			cout << _y << " ";
		}
	}
	cout << endl;
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}
