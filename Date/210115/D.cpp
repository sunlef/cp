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
map<string, int> mp;
void solve(){
	int n;
	cin >> n;
	string str;
	while(n--){
		cin >> str;
		if(mp[str]++ == 0)
			cout << "OK" << endl;
		else
			cout << str << mp[str]-1 << endl;
	}

}
int main(){
	SYNC;
	solve();
}
