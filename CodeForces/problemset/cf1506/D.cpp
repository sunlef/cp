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
int n;
map<int, int> mp;
map<int, bool> mp2;
vector<int> v;
int a[MAXN];
void solve(){
	mp.clear();
	mp2.clear();
	v.clear();
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]; 
	for(int i = 1; i <= n; ++i){
		++mp[a[i]];
		mp2[a[i]] = false;
	}
	for(int i = 1; i <= n; ++i){
		if(!mp2[a[i]]){
			v.push_back(mp[a[i]]);
			mp2[a[i]] = true;
		}
	}
	for(auto i : v){
		if(i % 2 == 0){
			
		}
	}
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}
