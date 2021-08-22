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
void solve(){
	cin >> s;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
			continue;
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
			continue;
		cout << '.';
		if(s[i] >= 'A' && s[i] <= 'Z')
			cout << (char)(s[i]+('a'-'A'));
		else
			cout << s[i];
	}
	cout << endl;
}
int main(){
	SYNC;
	solve();
}
