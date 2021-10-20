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
int d;
bool check(int x){
	vector<int> v;
	for(int i = 1; i <= x; ++i){
		if(v.size() >= 4)
			break;
		if(x % i == 0)
			v.push_back(i);
	}
	if(v.size() < 4)
		return false;
	else
		return v[1] - v[0] >= d;
}
void solve(){
//	freopen("baoli.txt", "w", stdout);
	for(int i = 1; i <= 200; ++i){
		d = i;
		for(int j = 1; j <= INF; ++j){
			if(check(j)){
				cout << i << ": " << j << endl;
				break;
			}
		}
	}
}
int main(){
	SYNC;
	solve();
}
