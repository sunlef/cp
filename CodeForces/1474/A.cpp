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
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool last_is_2 = false;
	bool last_is_1 = false;
	bool last_is_0 = false;
	for(int i = 0; i <= s.size()-1; ++i){
		if(s[i] == '1'){
			if(last_is_2 == false){
				cout << 1;
				last_is_2 = true;
				last_is_1 = false;
				last_is_0 = false;
			}
			else if(last_is_1 == false){
				cout << 0;
				last_is_2 = false;
				last_is_1 = true;
				last_is_0 = false;
			}
		}
		else{
			if(last_is_1 == false){
				cout << 1;
				last_is_1 = true;
				last_is_2 = false;
				last_is_0 = false;
			}
			else if(last_is_0 == false){
				cout << 0;
				last_is_1 = false;
				last_is_2 = false;
				last_is_0 = true;
			}
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
