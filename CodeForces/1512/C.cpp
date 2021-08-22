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
int a, b;
string s;
void solve(){
	cin >> a >> b;
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len/2; ++i){
		if(s[i] == '?' && s[len-1-i] != '?')
			s[i] = s[len-1-i];
		else if(s[i] != '?' && s[len-1-i] == '?')
			s[len-1-i] = s[i];
	}
	int cntST = 0;
	for(int i = 0; i < len; ++i){
		if(s[i] == '1')
			--b;
		else if(s[i] == '0')
			--a;
		else
			++cntST;
	}
	if(len % 2 == 1 && s[len/2] == '?'){
		if(a % 2 == 1){
			s[len/2] = '0';
			--a;
		}
		else if(b % 2 == 1){
			s[len/2] = '1';
			--b;
		}
		else{
			cout << -1 << endl;
			return;
		}
		--cntST;
	}
	if(cntST % 2 == 1 || a % 2 == 1 || b % 2 ==1){
		cout << -1 << endl;
		return;
	}
	if(a < 0 || b < 0 || cntST != a+b){
		cout << -1 << endl;
		return;
	}
	if(cntST == 0){
		for(int i = 0; i < len/2; ++i){
			if(s[i] != s[len-1-i]){
				cout << -1 << endl;
				return;
			}
		}
	}
	for(int i = 0; i < len/2; ++i){
		if(s[i] == '?'){
			if(a>1){
				s[i] = s[len-1-i] = '0';
				a -= 2;
			}
			else if(b>1){
				s[i] = s[len-1-i] = '1';
				b -= 2;
			}
		}
	}
		for(int i = 0; i < len/2; ++i){
			if(s[i] != s[len-1-i]){
				cout << -1 << endl;
				return;
			}
		}

	cout << s << endl;
}
int main(){
	SYNC;
	int T;
	cin >> T;
	while(T--)
		solve();
}
