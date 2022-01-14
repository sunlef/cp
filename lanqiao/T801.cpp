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
string s;
int cnt[26];
void solve(){
	cin >> s;
	for(int i = 0; i < s.size(); ++i)
		++cnt[s[i]-'a'];
	int maxx = -INF;
	char ans = 0;
	for(int i = 0; i < 26; ++i)
		if(cnt[i] > maxx){
			maxx = cnt[i];
			ans = i+'a';
		}
	cout << ans << endl << maxx << endl;
}
int main(){
	SYNC;
	solve();
}
