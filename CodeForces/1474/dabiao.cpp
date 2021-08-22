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
	int cnt = 0;
	for(int i = 2; i < x; ++i){
		if(v.size() >= 2)
			break;
		if(x % i == 0)
			v.push_back(i);
	}
	if(v.size() < 2)
		return false;
	return v[0] >= d + 1;
}
void solve(){
//	freopen("dabiao.txt", "w", stdout);
	cout << "long long ans[10002] = {";
	for(int i = 9990; i <= 10000; ++i){
		d = i;
		for(int j = 6; j <= INF; ++j){
			if(check(j)){
				cout << i <<": " << j << endl;
				break;
			}
		}
	}
	cout << "0};";
}
int main(){
	SYNC;
	solve();
}
