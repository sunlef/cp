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
void solve(){
	char ch[3];
	for(int i = 0; i <= 2; ++i)
		cin >> ch[i];
	cout << (ch[0] == ch[1] && ch[1] == ch[2] ? "Won" : "Lost") << endl;
}
int main(){
	SYNC;
	solve();
}
